#pragma once

#include <memory>

#include "main.h"
#include "okapi/api/util/mathUtil.hpp"
#include "okapi/impl/chassis/controller/chassisControllerBuilder.hpp"
#include "robot_constants.hpp"

namespace src::Chassis {

static constexpr float TURN_FACTOR = 0.65f;

static MotorGroup left_chassis_group = {
    Motor(CHASSIS_PORT_L1, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees),
    Motor(CHASSIS_PORT_L2, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees),
    Motor(CHASSIS_PORT_L3, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees)};

static MotorGroup right_chassis_group = {
    Motor(CHASSIS_PORT_R1, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees),
    Motor(CHASSIS_PORT_R2, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees),
    Motor(CHASSIS_PORT_R3, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees)};

extern std::shared_ptr<ChassisController> chassis;
extern pros::Imu imuSensor;

extern void initialize();

extern void update();

extern void act();

extern void movePID(float leftTarget, float rightTarget, int ms, float maxV = 1);
extern void turnPID(float degrees, bool CW, float maxV = 1);
extern void gyroPID(int degree, bool CW, int ms = 1000);

} // namespace src::Chassis