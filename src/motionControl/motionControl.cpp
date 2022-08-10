#pragma once
#include "motionControl.hpp"
#include "okapi/api/util/mathUtil.hpp"
#include "robot_constants.hpp"

namespace src::MotionControl {
    MotionControl::MotionControl(std::shared_ptr<ChassisController> chassis) {
        this->chassis = chassis;
    }

    void MotionControl::movePID(float leftTarget, float rightTarget, int ms, float maxV) {
        double degreesLeft = (leftTarget * 360) / (pi * WHEEL_DIAMETER);
        double degreesRight = (rightTarget * 360) / (pi * WHEEL_DIAMETER);
        // Create PID controllers for each side of the chassis
        auto drivePIDL = okapi::IterativeControllerFactory::posPID(P_GAIN, I_GAIN, D_GAIN);
        auto drivePIDR = okapi::IterativeControllerFactory::posPID(P_GAIN, I_GAIN, D_GAIN);
        // Reset Chassis sensors
        this->chassis->getModel()->resetSensors();

        int timer = 0;
        float errorLeft;
        float errorRight;
        float powerLeft;
        float powerRight;
        while (timer < ms) {
            errorLeft = degreesLeft + this->chassis->getModel()->getSensorVals()[0];
        }
    }

    void MotionControl::turnPID(float degrees, bool CW, int ms, float maxV) {
    }

    void MotionControl::gyroPID(int degree) {
    }

} // namespace src::MotionControl