#include "hppfiles/robot.hpp"

Robot::Robot(RobotType robotType, RobotSize robotSize, int robotId)
    : type(robotType), size(robotSize), batteryLevel(maxBattery), robotId(robotId), status(RobotStatus::AVAILABLE) {}

Robot::~Robot() {}

void Robot::setBatteryLevel(int newBatteryLevel)
{
    if (newBatteryLevel > maxBattery) {
        batteryLevel = maxBattery;
    }
    else {
        batteryLevel = newBatteryLevel;
    }
}

void Robot::setRobotStatus(RobotStatus newStatus)
{
    status = newStatus;
}