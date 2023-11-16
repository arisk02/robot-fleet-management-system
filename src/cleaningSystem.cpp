#include "hppfiles/cleaningSystem.hpp"
#include <iostream>

namespace cleaningSys {


    cleaningSystem::cleaningSystem() { 
        rooms.push_back(Room(Room::Size::medium, true, 1));
        robots.push_back(new Mopper(RobotSize::LARGE, 2));
        robots.push_back(new Mopper(RobotSize::MEDIUM, 3));
        robots.push_back(new Mopper(RobotSize::SMALL, 4));
        robots.push_back(new Vacuum(RobotSize::MEDIUM, 5));
        robots.push_back(new Scrubber(RobotSize::MEDIUM, 6));
        robots.push_back(new Mopper(RobotSize::MEDIUM, 7));
    }

    cleaningSystem::cleaningSystem( int smallScrubbers, int mediumScrubbers, int largeScrubbers,
                                    int smallVacuums, int mediumVacuums, int largeVacuums,
                                    int smallMoppers, int mediumMoppers, int largeMoppers,
                                    int smallRooms, int mediumRooms, int largeRooms){

        for(int i = 0; i < smallScrubbers; i++){
            robots.push_back(new Scrubber(RobotSize::SMALL, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < mediumScrubbers; i++){
            robots.push_back(new Scrubber(RobotSize::MEDIUM, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < largeScrubbers; i++){
            robots.push_back(new Scrubber(RobotSize::LARGE, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < smallVacuums; i++){
            robots.push_back(new Vacuum(RobotSize::SMALL, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < mediumVacuums; i++){
            robots.push_back(new Vacuum(RobotSize::MEDIUM, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < largeVacuums; i++){
            robots.push_back(new Vacuum(RobotSize::LARGE, robotCounter));
            robotCounter++;
        }
        
        for(int i = 0; i < smallMoppers; i++){
            robots.push_back(new Mopper(RobotSize::SMALL, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < mediumMoppers; i++){
            robots.push_back(new Mopper(RobotSize::MEDIUM, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < largeMoppers; i++){
            robots.push_back(new Mopper(RobotSize::LARGE, robotCounter));
            robotCounter++;
        }

        for(int i = 0; i < smallRooms; i++){
            rooms.push_back(Room(Room::Size::small, true, roomCounter));
            roomCounter++;
        }

        for(int i = 0; i < mediumRooms; i++){
            rooms.push_back(Room(Room::Size::medium, true, roomCounter));
            roomCounter++;
        }

        for(int i = 0; i < largeRooms; i++){
            rooms.push_back(Room(Room::Size::large, true, roomCounter));
            roomCounter++;
        }
        
    }

    cleaningSystem::~cleaningSystem() {
        for(auto&& robot : robots){
            delete robot;
        }
    }

    vector<Robot*> cleaningSystem::getRobots(vector<int> ids){
        std::vector<Robot*> selectedRobots;
        for (int id : ids){
            for (int i = 0; i < robots.size(); i++){
                if (robots.at(i)->getRobotId() == id){
                    selectedRobots.push_back(robots.at(i));
                }
            }
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
        for(Room& room : rooms){
            if(room.getId() == roomid){
                room.setOccupiedByRobot(true);
            }
        }
        for(int id : listRobots){
            for(Robot* robot : robots){
                if(robot->getRobotId() == id) {
                    robot->setLastUsed(time(0));
                    robot->setRobotStatus(RobotStatus::CLEANING);
                    robot->performTask();
                }
            }
        }
    }
    void cleaningSystem::repair(int robot){
        
    }
    void cleaningSystem::recharge(int robot){
        
    }

}