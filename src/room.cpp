#include "hppfiles/room.hpp"


    Room::Room() : size(Size::medium), clean(true), occupiedByRobot(false), RoomId(0) {} //default constructor

    Room::Room(Size newSize, bool newClean, int id) : size(newSize), clean(newClean), occupiedByRobot(false), RoomId(id) {} //constructor

/*
    void setSize(Room::Size newSize) { 
        size = newSize;
    }

    void setClean(bool newClean) {
        clean = newClean;
    }
    bool getClean() {
        if (occupiedByRobot == true) { //cleaning in progress so not clean
            return false;
        }
        else {
            bool result = (rand() / (double)RAND_MAX) < 0.75; // use probabilty to decide clean or not.
            return result;
        }
     }
*/
