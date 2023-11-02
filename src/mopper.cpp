#include "hppfiles/mopper.hpp"
#include <iostream>

Mopper::Mopper(RobotSize robotSize, int robotId) : Robot(RobotType::MOPPER, robotSize, robotId) {}

void Mopper::performTask() const { // This should clean the room, but we do not have Room class yet, so this will be changed
    std::cout << "Mopping the floor." << std::endl; // for now just print that it is doing its task
}