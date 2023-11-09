#ifndef VACUUM_HPP
#define VACUUM_HPP

#include "robot.hpp"

class Vacuum : public Robot {
public:
    Vacuum(RobotSize robotSize, int robotId);
    //void performTask() const override;
};

#endif