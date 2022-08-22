#pragma once
#include "motionControl.hpp"
#include "okapi/api/util/mathUtil.hpp"
#include "robot_constants.hpp"

namespace src::MotionControl {
MotionControl::MotionControl(std::shared_ptr<ChassisController> chassis) {
    this->chassis = chassis;
}

void MotionControl::movePID(float leftTarget, float rightTarget, int ms, float maxV) {
    float degreesL = (leftTarget * 360) / (pi * WHEEL_DIAMETER);
    float degreesR = (rightTarget * 360) / (pi * WHEEL_DIAMETER);
    // Create PID controllers for each side of the chassis
    auto drivePIDL = okapi::IterativeControllerFactory::posPID(P_GAIN, I_GAIN, D_GAIN);
    auto drivePIDR = okapi::IterativeControllerFactory::posPID(P_GAIN, I_GAIN, D_GAIN);
    // Reset Chassis sensors
    this->chassis->getModel()->resetSensors();
    // Initialize loop variables
    int timer = 0;
    float errorL;
    float errorR;
    float powerL;
    float powerR;
    while (timer < ms) { // Within time limit, increment PID loop
        errorL = degreesL + this->chassis->getModel()->getSensorVals()[0];
        errorR = degreesR + this->chassis->getModel()->getSensorVals()[1];
        powerL = drivePIDL.step(errorL);
        powerR = drivePIDR.step(errorR);
        this->chassis->getModel()->tank(powerL * maxV, powerR * maxV);
        pros::delay(10);
        timer += 10;
    }
    this->chassis->getModel()->tank(0, 0);
}

void MotionControl::turnPID(float degrees, bool CW, float maxV) {
    // The robot will turn in place around a circle with circumference of PI * radiusOfWheelTrack
    float turningCircleCircumference = pi * WHEEL_TRACK;
    float wheelDistance = turningCircleCircumference / 360 * degrees;
    int turnTimer = 1500; // Turns should always take at least 1.5 seconds
    if (CW) {
        this->movePID(wheelDistance, -1 * wheelDistance, turnTimer, maxV);
    } else {
        this->movePID(-1 * wheelDistance, wheelDistance, turnTimer, maxV);
    }
}

// void MotionControl::gyroPID(int degree, bool CW) {
//     this->imu.set_rotation(0);
//     int timer = 0;
//     float prevError = 0;
//     float integral = 0;
//     while (timer < 75) { // -> 75 * 20ms = 1500ms
//         float sensorVal = this->imu.get_rotation();
//         float error = degree - sensorVal;
//         float derivative = error - prevError;
//         prevError = error;
//         integral += error;
//         float power = (P_GAIN_TURN * error) + (I_GAIN_TURN * integral) + (D_GAIN_TURN * derivative);
//         if (CW) {
//             this->chassis->getModel()->tank(power, -1 * power);
//         } else {
//             this->chassis->getModel()->tank(-1 * power, power);
//         }
//         timer++;
//         pros::delay(20);
//     }
//     this->chassis->getModel()->tank(0, 0);
// }

} // namespace src::MotionControl