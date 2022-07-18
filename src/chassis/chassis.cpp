#include "chassis.hpp"

#include "main.h"
#include "robot_constants.hpp"

namespace src::Chassis {

std::shared_ptr<ChassisController> chassis = ChassisControllerBuilder()
                                                 .withMotors(left_chassis_group, right_chassis_group)
                                                 .withDimensions(AbstractMotor::gearset::green, {{4_in, 8_in}, imev5GreenTPR})
                                                 .build();

}
