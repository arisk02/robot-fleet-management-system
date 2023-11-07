#include "hppfiles/system.hpp"

system::system() : {
    &rooms.push_back(Roon:Roon(Size::Medium, true));
    &robots.push_back(Mopper::Mopper(RobotSize::SMALL, int 1));
    &robots.push_back(Mopper::Mopper(RobotSize::MEDIUM, int 2));
    &robots.push_back(Mopper::Mopper(RobotSize::LARGE, int 3));
    &robots.push_back(Scrubber::Scrubber(RobotSize::SMALL, int 4));
    &robots.push_back(Scrubber::Scrubber(RobotSize::LARGE, int 5));
    &robots.push_back(Vacuum::Vacuum(RobotSize::LARGE, int 6));
    &robots.push_back(Vacuum::Vacuum(RobotSize::MEDIUM, int 7));
}