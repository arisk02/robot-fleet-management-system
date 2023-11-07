#ifndef HPPFILES_SYSTEM_HPP
#define HPPFILES_SYSTEM_HPP
#include <list>
#include "robot.hpp"
#include "room.hpp"

using namespace std;
namespace system
{
    class system {
        private:
        std::list<Robot::Robot> *robots;
        std::list<Room::Room> *rooms;

        public:
        list<string> queryRobotStatus(list<Robot::Robot> listRobots);
        list<string> queryRoomStatus(list<Room::Room> listRooms);
        void clean(Room::Room room,list<Robot::Robot> listRobots);
        void repair(string robot);
        void recharge(string robot);

    }
}
#endif