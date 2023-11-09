#include "hppfiles/robot.hpp"

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

//Robot::~Robot() {}

//copy constructor
Robot::Robot(const Robot& bot) : type(bot.type), size(bot.size), batteryLevel(bot.batteryLevel), robotId(bot.robotId), status(bot.status), cleanTime(bot.cleanTime), lastUsed(bot.lastUsed) {
}

//move constructor
Robot::Robot(Robot&& bot) : type(bot.type), size(bot.size), batteryLevel(bot.batteryLevel), robotId(bot.robotId), status(bot.status), cleanTime(bot.cleanTime), lastUsed(bot.lastUsed) {
    bot.batteryLevel = NULL;
    bot.cleanTime = NULL;
    bot.lastUsed = NULL;
}

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