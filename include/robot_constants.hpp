#pragma once
#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/impl/device/motor/motor.hpp"
#include "okapi/impl/device/motor/motorGroup.hpp"

const MotorGroup LEFT_CHASSIS = {Motor(15, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                                 Motor(16, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                                 Motor(17, true, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)};

const MotorGroup RIGHT_CHASSIS = {Motor(9, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                                  Motor(10, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees),
                                  Motor(14, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees)};
