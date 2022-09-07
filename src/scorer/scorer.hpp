#pragma once

#include "main.h"
#include "pros/adi.hpp"
#include "robot_constants.hpp"

namespace src::Scorer {

enum class FlywheelStates {
    STOPPED = 0,
    RUNNING = 1,
};

enum class IntakeStates {
    STOPPED = 0,
    IN = 1,
    OUT = 2,
};

enum class GateStates {
    UP = 0,
    DOWN = 1,
};

typedef struct PID {
    float kP;
    float kI;
    float kD;
    float integral;
    float derivative;
    float error;
    float previousError;
    float speed;
    float target;
    float sensor;
} pid_t;

pid_t FW;

int flywheelToggleState = 0;
const int FLYWHEEL_MAX_TOGGLE = 2;

extern void initialize();
extern void update();
extern void act();

void flywheelVelocityControlTask(void *);
void flywheelToggleTask(void *);

static Motor flywheelMotor = Motor(FLYWHEEL_PORT, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
static Motor intakeMotor = Motor(INTAKE_PORT, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

static pros::ADIDigitalOut gate = pros::ADIDigitalOut(GATE_PORT, static_cast<bool>(GateStates::UP));

} // namespace src::Scorer