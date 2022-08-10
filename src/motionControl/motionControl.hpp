#pragma once
#include "main.h"
#include "okapi/impl/chassis/controller/chassisControllerBuilder.hpp"
#include <memory>

namespace src::MotionControl {
    class MotionControl {
      public:
        MotionControl(std::shared_ptr<ChassisController> chassis);

        void movePID(float leftTarget, float rightTarget, int ms, float maxV = 1);
        void turnPID(float degrees, bool CW, int ms, float maxV = 1);
        void gyroPID(int degree);

      private:
        std::shared_ptr<ChassisController> chassis;
    };
}; // namespace src::MotionControl
