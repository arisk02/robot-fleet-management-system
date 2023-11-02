#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
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

public:
    Room(); // Default constructor
    Room(Size newSize, bool newClean); // Constructor

    Size getSize();
    void setSize(Size newSize);
    void setClean(bool newClean);
    bool getClean();
};

#endif