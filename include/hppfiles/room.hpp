#ifndef ROOM_HPP
#define ROOM_HPP

#include <cstdlib> 

class Room {
public:
    enum class Size {
        small,
        medium,
        large
    };

private:
    Size size; 
    bool clean;
    bool occupiedByRobot;
    int RoomId;

public:
    Room(); // Default constructor
    Room(Size newSize, bool newClean, int id); // Constructor

    inline int getId() const{return RoomId;}
    inline Size getSize() const{return size;}
    inline void setSize(Size newSize) {size = newSize;}
    inline void setClean(bool newClean) {clean = newClean;}
    inline bool getClean() {return clean;}
    inline bool getOccupiedByRobot() {return occupiedByRobot;}
    inline void setOccupiedByRobot(bool newOccupied) {occupiedByRobot = newOccupied;}
};

#endif
