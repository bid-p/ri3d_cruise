#include "chassis.hpp"

#include "common.h"
#include "main.h"
#include "okapi/impl/device/controllerUtil.hpp"
#include "pros/misc.h"
#include "robot_constants.hpp"

namespace src::Chassis {

std::shared_ptr<ChassisController> chassis =
    ChassisControllerBuilder()
        .withMotors(left_chassis_group, right_chassis_group)
        .withDimensions(
            AbstractMotor::gearset::blue,
            {{4_in, 8_in}, imev5BlueTPR}) // {Wheelbase Width, Length}
        .build();

void initialize() {
  left_chassis_group.setBrakeMode(AbstractMotor::brakeMode::brake);
  right_chassis_group.setBrakeMode(AbstractMotor::brakeMode::brake);
}

void update() {}

void act() {
  Chassis::chassis->getModel()->arcade(
      controller.getAnalog(ControllerAnalog::leftY),
      TURN_LIMITING * controller.getAnalog(ControllerAnalog::rightX));
}

} // namespace src::Chassis
