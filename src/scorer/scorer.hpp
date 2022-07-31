#pragma once

#include "main.h"
#include "robot_constants.hpp"

namespace src::Scorer {

enum class FlywheelStates {
    STOPPED = 0,
    RUNNING = 1,
};

enum class IntakeStates {
    STOPPED = 0,
    IN = 1,
    OUT = 2,
};

extern void initialize();
extern void update();
extern void act();

static Motor flywheelMotor = Motor(FLYWHEEL_PORT, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
static Motor intakeMotor = Motor(INTAKE_PORT, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

}  // namespace src::Scorer