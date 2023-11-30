#ifndef HPPFILES_SYSTEM_HPP
#define HPPFILES_SYSTEM_HPP
#include "robot.hpp"
#include "room.hpp"
#include "mopper.hpp"
#include "scrubber.hpp"
#include <string>
#include "vacuum.hpp" 
#include <vector>
#include <map>
#include <future>
#include <fstream>

using namespace std;
namespace cleaningSys
{
    class cleaningSystem {
        private:
        std::map<int, Robot*> robots;
        std::map<int, Room> rooms;
        vector<Robot*> getRobots(vector<int> ids);
        vector<future<void>> futures;
        int roomCounter = 0;
        int robotCounter = 0;
        string logFilename;

        public:
        cleaningSystem();
        cleaningSystem(int smallScrubbers, int mediumScrubbers, int largeScrubbers,
                       int smallVacuums, int mediumVacuums, int largeVacuums,
                       int smallMoppers, int mediumMoppers, int largeMoppers,
                       int smallRooms, int mediumRooms, int largeRooms);
        ~cleaningSystem();
        vector<string> queryRobotStatus(vector<int> listRobots);
        vector<string> queryRobotStatus();//overload function that will query status of ALL robots
        vector<string> queryRoomStatus(vector<int> listRooms);
        vector<string> queryRoomStatus();//overload function that will query status of ALL rooms
        void clean(int room,vector<int> listRobots);
        void cleanAsync(vector<int> listRobots, int cleaningTime, int roomID);
        void repair(string robot);
        void recharge(string robot);
        void loggerSetup(string filename);
        void log();
        
        

    };
}
#endif