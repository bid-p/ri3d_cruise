#pragma once

#include <memory>

#include "main.h"
#include "okapi/api/util/mathUtil.hpp"
#include "okapi/impl/chassis/controller/chassisControllerBuilder.hpp"
#include "robot_constants.hpp"

namespace src::Chassis {

static const MotorGroup left_chassis_group = {Motor(CHASSIS_PORT_L1, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                                              Motor(CHASSIS_PORT_L2, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                                              Motor(CHASSIS_PORT_L3, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)};

static const MotorGroup right_chassis_group = {Motor(CHASSIS_PORT_R1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                                               Motor(CHASSIS_PORT_R2, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                                               Motor(CHASSIS_PORT_R3, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)};

extern std::shared_ptr<ChassisController> chassis;

}  // namespace src::Chassis