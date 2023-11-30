#include "hppfiles/cleaningSystem.hpp"
#include <iostream>
#include <string>
#include <fmt/core.h>
#include <cstdlib>
#include <unistd.h>
#include <chrono>

namespace cleaningSys {


    cleaningSystem::cleaningSystem() { 
        rooms[1] = (Room(Room::Size::medium, true, 1));
        robots[1] = (new Mopper(RobotSize::LARGE, 2));
        robots[2] = (new Mopper(RobotSize::MEDIUM, 3));
        robots[3] = (new Mopper(RobotSize::SMALL, 4));
        robots[4] = (new Vacuum(RobotSize::MEDIUM, 5));
        robots[5] = (new Scrubber(RobotSize::MEDIUM, 6));
        robots[6] = (new Mopper(RobotSize::MEDIUM, 7));
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
        std::vector<string> statusList;
        for (int id : listRobotints){
            statusList.push_back(std::to_string(id));
            RobotStatus temp = robots.at(id)->getRobotStatus();
            if(temp==RobotStatus::CLEANING){
                statusList.push_back("Cleaning");
            }
            else if (temp==RobotStatus::BROKEN){
                statusList.push_back("Broken");
            }
            else {
                statusList.push_back("Availible");
            }
            statusList.push_back(std::to_string(robots.at(id)->getRobotBatteryLevel()));
        }
        return statusList;
    }
    vector<string> cleaningSystem::queryRobotStatus()//overload function that will query status of ALL robots
    {
        std::vector<string> statusList;
        for (auto bot : robots){
            statusList.push_back(std::to_string(bot.first));
            switch (bot.second->getRobotStatus())
            {
            case RobotStatus::CLEANING:
                statusList.push_back("Cleaning");
                break;
            case RobotStatus::BROKEN:
                statusList.push_back("Broken");
                break;
            default:
                statusList.push_back("Availible");
                break;
            }
            statusList.push_back(std::to_string(bot.second->getRobotBatteryLevel()));
        }
        return statusList;
    }

    vector<string> cleaningSystem::queryRoomStatus(vector<int> listRooms){
        std::vector<string> statusList;
        for (int id : listRooms){
            statusList.push_back(to_string(id));
            Room::Size temp = rooms.at(id).getSize();
            if(temp==Room::Size::small){
                statusList.push_back("small");
            }
            else if(temp==Room::Size::medium){
                statusList.push_back("medium");
            }
            else{
                statusList.push_back("large");
            }
            if (rooms.at(id).getClean()){
                statusList.push_back("Clean");
            }
            else {
                statusList.push_back("Dirty");
            }
            if (rooms.at(id).getOccupiedByRobot()){
                statusList.push_back("occupied by robot");
            }
            else {
                statusList.push_back("not occupied by robot");
            }
            
        }
        return statusList;
    }

    vector<string> cleaningSystem::queryRoomStatus()//overload function that will query status of ALL rooms
    {
        std::vector<string> statusList;
        for (auto room : rooms){
            statusList.push_back(to_string(room.first));
            switch (room.second.getSize())
            {
            case Room::Size::small:
                statusList.push_back("small");
                break;
            case Room::Size::medium:
                statusList.push_back("medium");
            case Room::Size::large:
                statusList.push_back("large");
            }
            if (room.second.getClean()){
                statusList.push_back("Clean");
            }
            else {
                statusList.push_back("Dirty");
            }
            if (room.second.getOccupiedByRobot()){
                statusList.push_back("occupied by robot");
            }
            else {
                statusList.push_back("not occupied by robot");
            }
        }
        return statusList;
    }
    void cleaningSystem::clean(int roomid,vector<int> listRobots){
        std::unique_ptr<bool> roomOccupied (new bool (rooms[roomid].getOccupiedByRobot()));
        if (*roomOccupied){
            fmt::print("Error: Room {} already occupied by Robots.\n", roomid);
        }
        else{
            int totalBotSize = 0;
            for (int id : listRobots){//loop to add up total units/second cleaning ability for all robots in list
                if (robots.at(id)->getRobotStatus()==RobotStatus::CLEANING || robots[id]->getRobotStatus()==RobotStatus::BROKEN)
                {
                    fmt::print("Error: Robot {} is unavailable.\n", id);
                    return;
                }
                switch (robots.at(id)->getRobotSize()){//adds a robots ability to clean "units" of a room based on size.
                    case RobotSize::LARGE:
                        totalBotSize += 30;
                        break;
                    case RobotSize::MEDIUM:
                        totalBotSize += 20;
                        break;
                    case RobotSize::SMALL:
                        totalBotSize += 10;
                }
            }
            int cleaningTime = 0;
            switch (rooms[roomid].getSize()){//this switch uses the total weights of the robots calculated above to find the cleaning time in seconds it will take to clean the room
                case Room::Size::large:
                    cleaningTime = 1500/totalBotSize; //the initial integer in this expression is the "size" of the room. It can be thought of in the way that robots can clean a certain number of units per second, and this is the total units in a room
                    break;
                case Room::Size::medium:
                    cleaningTime = 1000/totalBotSize;
                    break;
                case Room::Size::small:
                    cleaningTime = 500/totalBotSize;
            }
            for (int id : listRobots){//sets the status of all robots to cleaning
                robots[id]->setRobotStatus(RobotStatus::CLEANING);
            }
            for (int i=0; i< futures.size();i++){//this loop goes through each future in the futures list and invalidates it and erases it from the list in hopes of mitigating memory leaks
                if (futures[i].wait_for(chrono::seconds(0))==future_status::ready){
                    futures[i].get();
                    futures.erase(futures.begin()+i);
                }
            }
            rooms[roomid].setClean(false);
            rooms.at(roomid).setOccupiedByRobot(true);
            futures.push_back(async(launch::async, &cleaningSystem::cleanAsync, this, listRobots, cleaningTime, roomid));
        }
        

    }
    void cleaningSystem::cleanAsync(vector<int> listRobots, int cleaningTime, int roomID){
        while (cleaningTime > 0)
        {
            srand((unsigned) time(NULL));
            for (int id : listRobots){
                int breakOdds = rand() % 500; //Change the mod integer here to alter the odds of a robot breaking every second during cleaning (for each robot). odds are 1 in {integer here}. ex. 1 in 500
                if (breakOdds == 1){
                    fmt::print("\nRobot {} has broken during the cleaning of room {}. The room will remain dirty until re-cleaned successfully.\n", id, roomID);
                    for (int resetID : listRobots){//sets all robots to availible after robot break event
                        robots.at(resetID)->setRobotStatus(RobotStatus::AVAILABLE);
                    }
                    robots.at(id)->setRobotStatus(RobotStatus::BROKEN);//broken robot gets set to broken
                    rooms[roomID].setOccupiedByRobot(false);
                    return;
                }
                if (robots.at(id)->getRobotBatteryLevel()<1){//check for dead robot
                    fmt::print("\nRobot {} is out of battery. The room will remain dirty until re-cleaned successfully.\n", id);
                    for (int resetID : listRobots){
                        robots.at(resetID)->setRobotStatus(RobotStatus::AVAILABLE);
                    }
                    rooms[roomID].setOccupiedByRobot(false);
                    return;
                }
                switch (robots.at(id)->getRobotSize()) //switch to deplete robot battery by preset amounts
                {
                case RobotSize::LARGE:
                    robots.at(id)->setBatteryLevel(robots.at(id)->getRobotBatteryLevel() - 1);
                    break;
                case RobotSize::MEDIUM:
                    robots.at(id)->setBatteryLevel(robots.at(id)->getRobotBatteryLevel() - 2);                    
                    break;
                default:
                    robots.at(id)->setBatteryLevel(robots.at(id)->getRobotBatteryLevel() - 4);
                    break;
                }

            }
            sleep(1);
            cleaningTime -= 1;
        }
        for (int resetID : listRobots){//reset all robot status'
            robots.at(resetID)->setRobotStatus(RobotStatus::AVAILABLE);
        }
        rooms.at(roomID).setClean(true);
        rooms.at(roomID).setOccupiedByRobot(false);
        return;
    }
    void cleaningSystem::repair(string robot){
        
    }
    void cleaningSystem::recharge(string robot){
        
    }

}