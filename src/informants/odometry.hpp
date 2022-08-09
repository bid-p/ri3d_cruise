#pragma once
#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/api/device/rotarysensor/continuousRotarySensor.hpp"
#include "okapi/api/device/rotarysensor/rotarySensor.hpp"
#include "okapi/api/odometry/odometry.hpp"
#include "okapi/api/util/mathUtil.hpp"
#include "okapi/impl/device/motor/motor.hpp"
#include "okapi/impl/device/motor/motorGroup.hpp"
#include "robot_constants.hpp"

/*
The purpose of this file and odometry.cpp is to contain the logic for odometry-related code
Odometry will need to access (or be updated) with encoder values
in order to determine the robot's absolute position (x,y) and orientation (z)
*/

namespace src::Odometry {

    class Odometry {
      public:
        Odometry(okapi::MotorGroup left_chassis_group, okapi::MotorGroup right_chassis_group,
                 okapi::RotarySensor left_encoder, okapi::RotarySensor right_encoder, okapi::RotarySensor back_encoder);

        void initialize();

        void update();

      private:
        okapi::MotorGroup left_chassis_group;
        okapi::MotorGroup right_chassis_group;
        okapi::RotarySensor left_encoder;
        okapi::RotarySensor right_encoder;
        okapi::RotarySensor back_encoder;
    };

} // namespace src::Odometry
