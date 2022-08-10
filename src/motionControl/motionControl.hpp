#pragma once
#include "main.h"
#include "okapi/impl/chassis/controller/chassisControllerBuilder.hpp"
#include "robot_constants.hpp"
#include <memory>

namespace src::MotionControl {
    class MotionControl {
      public:
        MotionControl(std::shared_ptr<ChassisController> chassis);

        void movePID(float leftTarget, float rightTarget, int ms, float maxV = 1);
        void turnPID(float degrees, bool CW, float maxV = 1);
        void gyroPID(int degree, bool CW);

      private:
        std::shared_ptr<ChassisController> chassis;
        pros::IMU imu = pros::Imu(IMU_PORT);
    };
}; // namespace src::MotionControl
