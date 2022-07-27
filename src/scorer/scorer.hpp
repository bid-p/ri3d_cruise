#pragma once

#include "main.h"
#include "robot_constants.hpp"

namespace src::Scorer {

static const Motor scorer1 = Motor(SCORER_PORT_1, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);
static const Motor scorer2 = Motor(SCORER_PORT_2, false, AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

extern void update();

}  // namespace src::Scorer