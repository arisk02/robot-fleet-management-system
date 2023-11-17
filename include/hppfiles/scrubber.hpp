#ifndef SCRUBBER_HPP
#define SCRUBBER_HPP

#include "robot.hpp"

class Scrubber : public Robot {
public:
    Scrubber(RobotSize robotSize, int robotId);
    void performTask() override;
};

#endif