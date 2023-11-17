#include "hppfiles/room.hpp"


    Room::Room() : size(Size::medium), clean(true), occupiedByRobot(false), RoomId(0) {} //default constructor

    Room::Room(Size newSize, bool newClean, int id) : size(newSize), clean(newClean), occupiedByRobot(false), RoomId(id) {} //constructor
