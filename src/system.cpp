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
list<string> queryRobotStatus(list<Robot::Robot> listRobotStrings){
    std::list<Robot::Robot> robotsList = getRobots(listRobotStrings);
    std::list<std::string> statusList;
    auto bots = robotsList.begin();
    for (int i=0, i<list::size(robotsList),i++){
        statusList.push_back(std::to_string(std::advance(bots, i).getRobotId()));
        RobotStatus temp = std::advance(bots, i).getRobotStatus();
        if(temp==RobotStatus::CLEANING){
            statusList.push_back("Cleaning");
        }
        else if (temp==RobotStatus::BROKEN){
            statusList.push_back("Broken")
        }
        else {
            statusList.push_back("Availible")
        }
        statusList.push_back(std::to_string(std::advance(bots, i).getRobotBatteryLevel()));
    }
    return statusList;
}
list<string> queryRoomStatus(list<string> listRooms){
    std::list<Room::Room> selectedRooms;
    auto allrooms = rooms.begin();
    for (string name : listRooms) {
        for (int i=0, i<list::size(rooms),i++){
            if (std::advance(allrooms, i).getRoomId == name) {//THIS WILL NEED UPDATING ONCE ROOM OBJ HAS ID
                selectedRooms.push_back(std::advance(allrooms, i));
            }
        }
    }
    auto roomsIT = selectedRooms.begin();
    std::list<std::string> statusList;
    for (int i=0, i<list::size(selectedRooms),i++){
        statusList.push_back(std::advance(roomsIT, i).getRoomId());//THIS WILL NEED UPDATING ONCE ROOM OBJ HAS ID
        Size temp = std::advance(roomsIT, i).getSize();
        if(temp==Size::small){
            statusList.push_back("small");
        }
        else if(temp==Size::medium){
            statusList.push_back("medium");
        }
        else{
            statusList.push_back("large");
        }
        if (std::advance(roomsIT, i).getClean()){
            statusList.push_back("Clean");
        }
        else {
            statusList.push_back("Dirty");
        }
        
    }
    return statusList;
}
void clean(Room::Room room,list<string> listRobots){
    return
}
void repair(string robot){
    return
}
void recharge(string robot){
    return
}
list<Robot::Robot> getRobots(list<string> ids){
    std::list<Robot::Robot> *selectedRobots;
    auto bots = robots.begin();
    for (string name : ids){
        for (int i = 0, i<list::size(robots),i++){
            if (std::advance(bots, i).getRobotId() == name){
                selectedRobots.push_back(std::advance(bots, i));
            }
        }
    }
    return selectedRobots;
}
