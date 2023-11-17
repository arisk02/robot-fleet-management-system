#include "hppfiles/robot.hpp"
#include <iostream>

Robot::Robot(RobotType robotType, RobotSize robotSize, int robotId)
    : type(robotType), size(robotSize), batteryLevel(100), robotId(robotId), 
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

void Robot::performTask() {}

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

void Robot::chargeRobot()
{
    setBatteryLevel(maxBattery);   
}

void Robot::fixRobot()
{
    setRobotStatus(RobotStatus::AVAILABLE);
}