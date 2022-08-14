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
                {{WHEEL_DIAMETER, WHEEL_TRACK}, imev5BlueTPR})
            .build();

    void initialize() {
        left_chassis_group.setBrakeMode(AbstractMotor::brakeMode::brake);
        right_chassis_group.setBrakeMode(AbstractMotor::brakeMode::brake);
    }

    void update() {}

    void act() {
        Chassis::chassis->getModel()->arcade(
            controller.getAnalog(ControllerAnalog::leftY),
            TURN_FACTOR * controller.getAnalog(ControllerAnalog::rightX));
    }

} // namespace src::Chassis
