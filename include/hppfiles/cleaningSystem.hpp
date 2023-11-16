#ifndef HPPFILES_SYSTEM_HPP
#define HPPFILES_SYSTEM_HPP
#include "robot.hpp"
#include "room.hpp"
#include "mopper.hpp"
#include "scrubber.hpp"
#include <string>
#include "vacuum.hpp" 
#include <vector>

using namespace std;
namespace cleaningSys
{
    class cleaningSystem {
        private:
        std::vector<Robot> robots;
        std::vector<Room> rooms;
        vector<Robot> getRobots(vector<int> ids);

        public:
        cleaningSystem();
        vector<string> queryRobotStatus(vector<int> listRobots);
        vector<string> queryRoomStatus(vector<int> listRooms);
        void clean(int room,vector<int> listRobots);
        void repair(string robot);
        void recharge(string robot);
        
        

    };
}
#endif