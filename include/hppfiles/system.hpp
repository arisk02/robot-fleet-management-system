#ifndef HPPFILES_SYSTEM_HPP
#define HPPFILES_SYSTEM_HPP
#include<list>

using namespace std;
namespace system
{
    class system {
        private:
        std::list<robot> *robots;
        std::list<room> *rooms;

        public:
        list<string> queryRobotStatus(list<robot> listRobots);
        list<string> queryRoomStatus(list<room> listRooms);
        void clean(room room,list<robot> listRobots);
        void repair(string robot);
        void recharge(string robot);

    }
}