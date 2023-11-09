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
        std::list<Robot> *robots;
        std::list<Room> *rooms;
        list<Robot> getRobots(list<string> ids);

        public:
        cleaningSystem();
        list<string> queryRobotStatus(list<string> listRobots);
        list<string> queryRoomStatus(list<string> listRooms);
        void clean(Room room,list<string> listRobots);
        void repair(string robot);
        void recharge(string robot);
        

    };
}
#endif