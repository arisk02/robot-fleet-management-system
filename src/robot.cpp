#include "hppfiles/robot.hpp"

Robot::Robot(RobotType robotType, RobotSize robotSize, int robotId)
    : type(robotType), size(robotSize), batteryLevel(maxBattery), robotId(robotId), 
    status(RobotStatus::AVAILABLE), cleanTime(0), lastUsed(time(0)) {
        if (robotSize == RobotSize::SMALL) {
            cleanTime = 15;
        }
        else if (robotSize == RobotSize::MEDIUM) {
            cleanTime = 10;
        }
        else {
            cleanTime = 5;
        }
    }

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

void Robot::setLastUsed(time_t newLastUsed)
{
    lastUsed = newLastUsed;
}