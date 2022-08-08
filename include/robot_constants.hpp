#pragma once
#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/impl/device/motor/motor.hpp"
#include "okapi/impl/device/motor/motorGroup.hpp"

static constexpr uint8_t CHASSIS_PORT_L1 = 6;
static constexpr uint8_t CHASSIS_PORT_L2 = 8;
static constexpr uint8_t CHASSIS_PORT_L3 = 5;

static constexpr uint8_t CHASSIS_PORT_R1 = 4;
static constexpr uint8_t CHASSIS_PORT_R2 = 7;
static constexpr uint8_t CHASSIS_PORT_R3 = 3;

static constexpr uint8_t FLYWHEEL_PORT = 2;
static constexpr uint8_t INTAKE_PORT = 1;

static constexpr uint8_t GATE_PORT = 'A';

static constexpr float TURN_FACTOR = 0.65f;