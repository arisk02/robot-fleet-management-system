#ifndef MOPPER_HPP
#define MOPPER_HPP

#include "robot.hpp"

class Mopper : public Robot {
public:
    Mopper(RobotSize robotSize, int robotId);
    //void performTask() const override;
};

#endif