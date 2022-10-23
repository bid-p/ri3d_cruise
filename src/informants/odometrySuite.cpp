#pragma once
#include "odometrySuite.hpp"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/api/device/rotarysensor/continuousRotarySensor.hpp"
#include "okapi/api/device/rotarysensor/rotarySensor.hpp"
#include "okapi/api/odometry/odometry.hpp"
#include "okapi/api/util/mathUtil.hpp"
#include "okapi/impl/device/motor/motor.hpp"
#include "okapi/impl/device/motor/motorGroup.hpp"
#include "okapi/impl/device/rotarysensor/adiEncoder.hpp"
#include "pros/rtos.hpp"
#include "robot_constants.hpp"

// See odometrySuite.hpp for documentation

namespace src::informants {
OdometrySuite::OdometrySuite() {}

void OdometrySuite::initialize() {
    this->left_encoder.reset();
    this->right_encoder.reset();
    this->xPosition = 0;
    this->yPosition = 0;
    this->orientation = 0;
    this->imu.reset();
    int time = pros::millis();
    int iter = 0;
    while (this->imu.is_calibrating()) {
        printf("IMU Calibrating... %d [ms]\n", iter);
        iter += 10;
        pros::delay(10);
    }
    printf("IMU Calibrated in %d [ms]\n", iter - time);
}

void OdometrySuite::update() {
    // Update new position using sensors
    // CTLE -> Center to Left Encoder, CTRE -> Center to Right Encoder, CTBE -> Center to Back Encoder
    // this->orientation = (leftTravel - rightTravel) / (CTLE + CTRE)
    this->orientation = (this->left_encoder.controllerGet() - this->right_encoder.controllerGet()) /
                        (CENTER_TO_LEFT_ENCODER + CENTER_TO_RIGHT_ENCODER);
    // this->xPosition = 2 * ( (backTravel / orientation) + CTBE) * sin(orientation / 2)
    // this->yPosition = 2 * ( (rightTravel / orientation) + CTRE) * sin(orientation / 2)
}

float OdometrySuite::getXPosition() { return this->xPosition; }
float OdometrySuite::getYPosition() { return this->yPosition; }
float OdometrySuite::getOrientation() { return this->orientation; }
} // namespace src::informants
