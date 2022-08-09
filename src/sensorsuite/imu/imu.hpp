#pragma once
#include "main.h"
#include "robot_constants.hpp"

namespace src::imu {
    class IMU {
      public:
        IMU();

        void initialize();

      private:
        pros::Imu imu;
    };
} // namespace src::imu
