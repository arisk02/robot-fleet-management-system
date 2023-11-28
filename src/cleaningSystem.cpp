#include "hppfiles/cleaningSystem.hpp"
#include <iostream>

namespace cleaningSys {


    cleaningSystem::cleaningSystem() { 
        rooms[1] = (Room(Room::Size::medium, true, 1));
        robots[2] = (new Mopper(RobotSize::LARGE, 2));
        robots[3] = (new Mopper(RobotSize::MEDIUM, 3));
        robots[4] = (new Mopper(RobotSize::SMALL, 4));
        robots[5] = (new Vacuum(RobotSize::MEDIUM, 5));
        robots[6] = (new Scrubber(RobotSize::MEDIUM, 6));
        robots[7] = (new Mopper(RobotSize::MEDIUM, 7));
    }

    cleaningSystem::cleaningSystem( int smallScrubbers, int mediumScrubbers, int largeScrubbers,
                                    int smallVacuums, int mediumVacuums, int largeVacuums,
                                    int smallMoppers, int mediumMoppers, int largeMoppers,
                                    int smallRooms, int mediumRooms, int largeRooms){

        for(int i = 0; i < smallScrubbers; i++){
            robots[robotCounter] = (new Scrubber(RobotSize::SMALL, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < mediumScrubbers; i++){
            robots[robotCounter] = (new Scrubber(RobotSize::MEDIUM, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < largeScrubbers; i++){
            robots[robotCounter] = (new Scrubber(RobotSize::LARGE, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < smallVacuums; i++){
            robots[robotCounter] = (new Vacuum(RobotSize::SMALL, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < mediumVacuums; i++){
            robots[robotCounter] = (new Vacuum(RobotSize::MEDIUM, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < largeVacuums; i++){
            robots[robotCounter] = (new Vacuum(RobotSize::LARGE, robotCounter));
            robotCounter++;
        }
        
        for(int i = 0; i < smallMoppers; i++){
            robots[robotCounter] = (new Mopper(RobotSize::SMALL, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < mediumMoppers; i++){
            robots[robotCounter] = (new Mopper(RobotSize::MEDIUM, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < largeMoppers; i++){
            robots[robotCounter] = (new Mopper(RobotSize::LARGE, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < smallRooms; i++){
            rooms[roomCounter] = (Room(Room::Size::small, true, roomCounter));
            roomCounter++;
        }

        for(int i = 0; i < mediumRooms; i++){
            rooms[roomCounter] = (Room(Room::Size::medium, true, roomCounter));
            roomCounter++;
        }

        for(int i = 0; i < largeRooms; i++){
            rooms[roomCounter] = (Room(Room::Size::large, true, roomCounter));
            roomCounter++;
        }
        
    }

    cleaningSystem::~cleaningSystem() {
        while (robotCounter > -1) {
            robotCounter--;
            delete robots[robotCounter];
        }
    }

    vector<Robot*> cleaningSystem::getRobots(vector<int> ids){
        std::vector<Robot*> selectedRobots;
        for (int id : ids){
            selectedRobots.push_back(robots[id]);
        }
        return selectedRobots;
    }

    vector<string> cleaningSystem::queryRobotStatus(vector<int> listRobotints){
        std::vector<Robot*> robotsList = getRobots(listRobotints);
        std::vector<string> statusList;
        for (int i=0; i<robotsList.size(); i++){
            statusList.push_back(std::to_string(robotsList.at(i)->getRobotId()));
            RobotStatus temp = robotsList.at(i)->getRobotStatus();
            if(temp==RobotStatus::CLEANING){
                statusList.push_back("Cleaning");
            }
            else if (temp==RobotStatus::BROKEN){
                statusList.push_back("Broken");
            }
            else {
                statusList.push_back("Availible");
            }
            statusList.push_back(std::to_string(robotsList.at(i)->getRobotBatteryLevel()));
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
            if (selectedRooms.at(i).getOccupiedByRobot()){
                statusList.push_back("occupied by robot");
            }
            else {
                statusList.push_back("not occupied by robot");
            }
            
        }
        return statusList;
    }
    void cleaningSystem::clean(int roomid,vector<int> listRobots){
    }
    void cleaningSystem::repair(string robot){
        
    }
    void cleaningSystem::recharge(string robot){
        
    }

}