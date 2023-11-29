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

using namespace std;
namespace cleaningSys
{
    class cleaningSystem {
        private:
        std::map<int, Robot*> robots;
        std::map<int, Room> rooms;
        vector<Robot*> getRobots(vector<int> ids);
        int roomCounter = 0;
        int robotCounter = 0;

        public:
        cleaningSystem();
        cleaningSystem(int smallScrubbers, int mediumScrubbers, int largeScrubbers,
                       int smallVacuums, int mediumVacuums, int largeVacuums,
                       int smallMoppers, int mediumMoppers, int largeMoppers,
                       int smallRooms, int mediumRooms, int largeRooms);
        ~cleaningSystem();
        vector<string> queryRobotStatus(vector<int> listRobots);
        vector<string> queryRoomStatus(vector<int> listRooms);
        void clean(int room,vector<int> listRobots);
        void repair(string robot);
        void recharge(string robot);
        
        

    };
}
#endif