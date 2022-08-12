#pragma once
#include "main.h"

// Motor Ports
static constexpr uint8_t CHASSIS_PORT_L1 = 6;
static constexpr uint8_t CHASSIS_PORT_L2 = 8;
static constexpr uint8_t CHASSIS_PORT_L3 = 5;

static constexpr uint8_t CHASSIS_PORT_R1 = 4;
static constexpr uint8_t CHASSIS_PORT_R2 = 7;
static constexpr uint8_t CHASSIS_PORT_R3 = 3;

static constexpr uint8_t FLYWHEEL_PORT = 2;
static constexpr uint8_t INTAKE_PORT = 1;

// Sensor Ports
static constexpr uint8_t GATE_PORT = 'A';
static constexpr uint8_t LEFT_ENCODER_PORT_A = 'B';  // Not wired yet
static constexpr uint8_t LEFT_ENCODER_PORT_B = 'C';  // Not wired yet
static constexpr uint8_t RIGHT_ENCODER_PORT_A = 'D'; // Not wired yet
static constexpr uint8_t RIGHT_ENCODER_PORT_B = 'E'; // Not wired yet
static constexpr uint8_t BACK_ENCODER_PORT_A = 'F';  // Not wired yet
static constexpr uint8_t BACK_ENCODER_PORT_B = 'G';  // Not wired yet
static constexpr uint8_t IMU_PORT = 10;              // Not wired yet

// Physical robot constants
static constexpr float_t WHEEL_DIAMETER = 4.125f;        // [in]
static constexpr float_t CENTER_TO_LEFT_ENCODER = 0.0f;  // [in]
static constexpr float_t CENTER_TO_RIGHT_ENCODER = 0.0f; // [in]
static constexpr float_t CENTER_TO_BACK_ENCODER = 0.0f;  // [in]
static constexpr float TURN_FACTOR = 0.65f;