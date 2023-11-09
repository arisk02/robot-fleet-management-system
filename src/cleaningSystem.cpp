#include "hppfiles/cleaningSystem.hpp"

namespace cleaningSystem {


    cleaningSystem::cleaningSystem() { 
        rooms.push_back(Room(Room::Size::medium, true));
        robots.push_back(Mopper(RobotSize::SMALL, 1));
        robots.push_back(Mopper(RobotSize::MEDIUM, 2));
        robots.push_back(Mopper(RobotSize::LARGE, 3));
        robots.push_back(Scrubber(RobotSize::SMALL, 4));
        robots.push_back(Scrubber(RobotSize::LARGE, 5));
        robots.push_back(Vacuum(RobotSize::LARGE, 6));
        robots.push_back(Vacuum(RobotSize::MEDIUM, 7));
    }
    vector<Robot> cleaningSystem::getRobots(vector<int> ids){
        std::vector<Robot> selectedRobots;
        for (int id : ids){
            for (int i = 0; i < robots.size(); i++){
                if (robots.at(i).getRobotId() == id){
                    selectedRobots.push_back(robots.at(i));
                }
            }
        }
        return selectedRobots;
    }
    vector<string> cleaningSystem::queryRobotStatus(vector<Robot> listRobotStrings){
        std::vector<Robot> robotsList = getRobots(listRobotStrings);
        std::vector<string> statusList;
        auto bots = robotsList.begin();
        for (int i=0; i<list::size(robotsList); i++){
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

    vector<string> cleaningSystem::queryRoomStatus(vector<string> listRooms){
        std::vector<Room> selectedRooms;
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
    void cleaningSystem::clean(Room::Room room,list<string> listRobots){
        return
    }
    void cleaningSystem::repair(string robot){
        return
    }
    void cleaningSystem::recharge(string robot){
        return
    }

}