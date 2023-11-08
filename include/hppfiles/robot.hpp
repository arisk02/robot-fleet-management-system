#ifndef HFILES_ROBOT_HPP
#define HFILES_ROBOT_HPP

// Enum class for robot type
enum class RobotType {MOPPER, VACUUM, SCRUBBER};

// Enum class for robot size
enum class RobotSize {SMALL, MEDIUM, LARGE};

// Enum class for robot status
enum class RobotStatus {CLEANING, BROKEN, AVAILABLE};

class Robot 
{
    public:
        Robot(RobotType robotType, RobotSize robotSize, int robotId);   // constructor
        virtual void performTask() const = 0;                           // virtual method that is implemented in Mopper, Scrubber, Vacuum
        virtual ~Robot();                                               // destructor

        inline int          getRobotId()            const{return robotId;}         // returns robotId
        inline RobotType    getRobotType()          const{return type;}            // returns robot type
        inline RobotSize    getRobotSize()          const{return size;}            // returns robot size
        inline RobotStatus  getRobotStatus()             {return status;}          // returns robot status
        inline int          getRobotBatteryLevel()       {return batteryLevel;}    // returns robot battery level

        void setRobotStatus(RobotStatus newStatus);  // sets robot status
        void setBatteryLevel(int batteryLevel);      // charges robot

    protected:
        const int robotId;
        const RobotType type;
        const RobotSize size;
        RobotStatus status;
        int batteryLevel;
        const int maxBattery = 100;
};

#endif