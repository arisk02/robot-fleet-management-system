#include "hppfiles/vacuum.hpp"
#include <iostream>

Vacuum::Vacuum(RobotSize robotSize, int robotId) : Robot(RobotType::VACUUM, robotSize, robotId) {}

void Vacuum::performTask() const { // This should clean the room, but we do not have Room class yet, so this will be changed
    std::cout << "Vacuuming the floor." << std::endl; // for now just print that it is doing its task
}