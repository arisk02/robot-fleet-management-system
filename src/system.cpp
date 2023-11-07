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
list<string> queryRobotStatus(list<Robot::Robot> listRobots){
    for (int i=0, i<list::size(&robots),i++){
        
    }
}
list<string> queryRoomStatus(list<Room::Room> listRooms){

}
void clean(Room::Room room,list<Robot::Robot> listRobots){

}
void repair(string robot){

}
void recharge(string robot){

}