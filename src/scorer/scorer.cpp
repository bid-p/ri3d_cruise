#include "scorer.hpp"

#include "common.h"
#include "okapi/api/control/async/asyncVelIntegratedController.hpp"
#include "okapi/impl/device/button/controllerButton.hpp"
#include "okapi/impl/device/controllerUtil.hpp"
#include "okapi/impl/device/motor/motor.hpp"
#include "robot_constants.hpp"

namespace src::Scorer {

typedef struct PID {
    float kP;
    float kI;
    float kD;
    float integral;
    float derivative;
    float error;
    float previousError;
    float target;
    float speed;
    float sensor;
} pid;

pid FW;

ControllerButton flywheelToggleTaskButton(ControllerDigital::L2);
int flywheelVelocityCounter = 0;
const int numVelocityStates = 2; // number of states for the flywheel velocity
void flywheelToggleTask(void *) {
    while (true) {
        if (flywheelToggleTaskButton.changedToPressed()) {
            // Increment and wrap counter
            flywheelVelocityCounter++;
            if (flywheelVelocityCounter > numVelocityStates) {
                flywheelVelocityCounter = 0;
            }
            // Handle counter state
            switch (flywheelVelocityCounter) {
                case 0:
                    FW.target = 0;
                    break;
                case 1:
                    FW.target = 2000;
                    break;
                case 2:
                    FW.target = 2500;
                    break;
            }
        }
    }
}

void flywheelVelocityControlTask(void *) {
    FW.kP = 0.1;
    FW.kI = 0;
    FW.kD = 0.05;
    while (true) {
        FW.sensor = flywheelMotor.getPosition();
        flywheelMotor.getEncoder().reset();
        FW.error = FW.target - FW.sensor;
        FW.integral += FW.error;
        FW.derivative = FW.error - FW.previousError;
        FW.previousError = FW.error;
        FW.speed = FW.kP * FW.error + FW.kI * FW.integral + FW.kD * FW.derivative;
        if (flywheelVelocityCounter == 0) {
            FW.speed = 0;
        } else if (FW.speed < 0.5) {
            FW.speed = 0.5;
        }
        flywheelMotor.controllerSet(FW.speed);
        intakeMotor.controllerSet(FW.speed);
        pros::delay(20);
    }
}

// AsyncVelIntegratedController FlywheelVelController(scorer1, {AbstractMotor::gearset::green, 1}, 600);

/**
 * @brief Scorer behavior:
 * - Flywheel-direct motor toggles on/off when L1 pressed
 * - Intake-direct motor toggles in/off when R1 pressed, will also turn the flywheel on if it isn't already
 * - Hold R2 to outtake
 */
ControllerButton flywheelToggle(ControllerDigital::up);
ControllerButton gateToggle(ControllerDigital::L1);
ControllerButton intakeToggle(ControllerDigital::R1);
ControllerButton outtakeBtn(ControllerDigital::R2);

GateStates currGateState = GateStates::UP;

FlywheelStates currFlywheelState = FlywheelStates::STOPPED;

IntakeStates currIntakeState = IntakeStates::STOPPED;
IntakeStates savedIntakeState = currIntakeState;

void initialize() {
    flywheelMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
    intakeMotor.setBrakeMode(AbstractMotor::brakeMode::brake); // Set to brake because we might want to hold a frisbee in the intake
}

void update() {
    // Intake state updating
    if (outtakeBtn.changedToPressed()) {
        savedIntakeState = currIntakeState;  // Save intake state from before outtake button was pressed
        currIntakeState = IntakeStates::OUT; // Outtake while outtake btn is pressed
    } else if (outtakeBtn.changedToReleased()) {
        currIntakeState = savedIntakeState; // Return to saved state when outtake btn is released
    }

    if (intakeToggle.changedToPressed()) {
        if (currIntakeState != IntakeStates::IN) { // Toggle intake state between IN and STOPPED
            currIntakeState = IntakeStates::IN;
            currFlywheelState = FlywheelStates::RUNNING; // If intake is running, run the flywheel as well
        } else {
            currIntakeState = IntakeStates::STOPPED;
        }
    }

    // Flywheel state updating
    if (flywheelToggle.changedToPressed()) {
        if (currFlywheelState != FlywheelStates::RUNNING) { // Toggle flywheel state between RUNNING and STOPPED
            currFlywheelState = FlywheelStates::RUNNING;
        } else {
            currFlywheelState = FlywheelStates::STOPPED;
        }
    }

    // Gate state updating
    if (gateToggle.changedToPressed()) { // Toggle gate state between UP and DOWN
        if (currGateState == GateStates::UP) {
            currGateState = GateStates::DOWN;
        } else {
            currGateState = GateStates::UP;
        }
    }
}

void act() {
    switch (currIntakeState) {
        case IntakeStates::IN:
            intakeMotor.moveVelocity(500);
            break;
        case IntakeStates::OUT:
            intakeMotor.moveVelocity(-300);
            break;
        case IntakeStates::STOPPED:
            intakeMotor.moveVelocity(0);
            break;
    }

    switch (currFlywheelState) {
        case FlywheelStates::RUNNING:
            flywheelMotor.moveVelocity(500);
            break;
        case FlywheelStates::STOPPED:
            flywheelMotor.moveVelocity(0);
            break;
    }

    switch (currGateState) {
        case GateStates::UP:
            gate.set_value(static_cast<bool>(GateStates::UP));
            break;
        case GateStates::DOWN:
            gate.set_value(static_cast<bool>(GateStates::DOWN));
            break;
    }
}

} // namespace src::Scorer