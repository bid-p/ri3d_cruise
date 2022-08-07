#pragma once
#include "main.h"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/impl/device/motor/motor.hpp"
#include "okapi/impl/device/motor/motorGroup.hpp"

// Motor Ports
static constexpr uint8_t CHASSIS_PORT_L1 = 6;
static constexpr uint8_t CHASSIS_PORT_L2 = 8;
static constexpr uint8_t CHASSIS_PORT_L3 = 5;

static constexpr uint8_t CHASSIS_PORT_R1 = 4;
static constexpr uint8_t CHASSIS_PORT_R2 = 7;
static constexpr uint8_t CHASSIS_PORT_R3 = 3;

static constexpr uint8_t FLYWHEEL_PORT = 2; // Motor closer to flywheel
static constexpr uint8_t INTAKE_PORT = 1;   // Motor connectd to ratchet

// Physical robot constants
static constexpr float_t WHEEL_DIAMETER = 4.125f;        // [in]
static constexpr float_t CENTER_TO_LEFT_ENCODER = 0.0f;  // [in]
static constexpr float_t CENTER_TO_RIGHT_ENCODER = 0.0f; // [in]
static constexpr float_t CENTER_TO_BACK_ENCODER = 0.0f;  // [in]
