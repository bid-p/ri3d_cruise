#pragma once
#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/api/device/rotarysensor/continuousRotarySensor.hpp"
#include "okapi/api/device/rotarysensor/rotarySensor.hpp"
#include "okapi/api/odometry/odometry.hpp"
#include "okapi/api/util/mathUtil.hpp"
#include "okapi/impl/device/motor/motor.hpp"
#include "okapi/impl/device/motor/motorGroup.hpp"
#include "okapi/impl/device/rotarysensor/adiEncoder.hpp"
#include "robot_constants.hpp"

/*
The purpose of this file and odometry.cpp is to contain the logic for odometry-related code
Odometry will need to access (or be updated) with encoder values
in order to determine the robot's absolute position (x,y) and orientation (z)
*/

namespace src::Odometry {

    class Odometry {
      public:
        Odometry();

        /**
         * @brief Initializes the odometry system and resets the on-board sensor-suite
         *
         */
        void initialize();

        /**
         * @brief Updates the pose of the robot using the on-board sensor-suite
         *
         */
        void update();

        // Getters
        float getXPosition();
        float getYPosition();
        float getOrientation();

      private:
        // Sensors
        okapi::ADIEncoder left_encoder = okapi::ADIEncoder(LEFT_ENCODER_PORT_A, LEFT_ENCODER_PORT_B);
        okapi::ADIEncoder right_encoder = okapi::ADIEncoder(RIGHT_ENCODER_PORT_A, RIGHT_ENCODER_PORT_B);
        pros::Imu imu = pros::Imu(IMU_PORT);
        // Control Variables
        float xPosition;
        float yPosition;
        float orientation;
    };

} // namespace src::Odometry
