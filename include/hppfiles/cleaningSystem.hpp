#ifndef HPPFILES_SYSTEM_HPP
#define HPPFILES_SYSTEM_HPP
#include <list>
#include <string>
#include "robot.hpp"
#include "room.hpp"
#include "mopper.hpp"
#include "scrubber.hpp"
#include "vacuum.hpp"

using namespace std;
namespace cleaningSystem
{
    class cleaningSystem {
        private:
        std::vector<Robot> robots;
        std::vector<Room> rooms;
        vector<Robot> getRobots(vector<string> ids);

        public:
        cleaningSystem();
        vector<string> queryRobotStatus(vector<string> listRobots);
        vector<string> queryRoomStatus(vector<string> listRooms);
        void clean(Room room,vector<string> listRobots);
        void repair(string robot);
        void recharge(string robot);
        
        

    };
}
#endif