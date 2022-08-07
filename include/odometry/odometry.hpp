#pragma once
#include "main.h"

/*
The purpose of this file and odometry.cpp is to contain the logic for odometry-related code
Odometry will need to access (or be updated) with encoder values
in order to determine the robot's absolute position (x,y) and orientation

Odometry.cpp will notably offer a moveToPose(x,y,theta) function that will
move the robot from its current position to the given position (x,y) with
the given orientation (theta)
*/