#include "hppfiles/cleaningSystem.hpp"

namespace cleaningSystem {


    cleaningSystem::cleaningSystem() { 
        rooms.push_back(Room(Room::Size::medium, true, 1));
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
    vector<string> cleaningSystem::queryRobotStatus(vector<int> listRobotints){
        std::vector<Robot> robotsList = getRobots(listRobotints);
        std::vector<string> statusList;
        for (int i=0; i<robotsList.size(); i++){
            statusList.push_back(std::to_string(robotsList.at(i).getRobotId()));
            RobotStatus temp = robotsList.at(i).getRobotStatus();
            if(temp==RobotStatus::CLEANING){
                statusList.push_back("Cleaning");
            }
            else if (temp==RobotStatus::BROKEN){
                statusList.push_back("Broken");
            }
            else {
                statusList.push_back("Availible");
            }
            statusList.push_back(std::to_string(robotsList.at(i).getRobotBatteryLevel()));
        }
        return statusList;
    }

    vector<string> cleaningSystem::queryRoomStatus(vector<int> listRooms){
        std::vector<Room> selectedRooms;
        for (int name : listRooms) {
            for (int i=0; i<rooms.size();i++){
                if (rooms.at(i).getId() == name) {
                    selectedRooms.push_back(rooms.at(i));
                }
            }
        }
        std::vector<string> statusList;
        for (int i=0; i<selectedRooms.size();i++){
            statusList.push_back(to_string(selectedRooms.at(i).getId()));
            Room::Size temp = selectedRooms.at(i).getSize();
            if(temp==Room::Size::small){
                statusList.push_back("small");
            }
            else if(temp==Room::Size::medium){
                statusList.push_back("medium");
            }
            else{
                statusList.push_back("large");
            }
            if (selectedRooms.at(i).getClean()){
                statusList.push_back("Clean");
            }
            else {
                statusList.push_back("Dirty");
            }
            
        }
        return statusList;
    }
    void cleaningSystem::clean(Room room,vector<int> listRobots){
        
    }
    void cleaningSystem::repair(string robot){
        
    }
    void cleaningSystem::recharge(string robot){
        
    }

}