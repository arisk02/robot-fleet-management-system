#ifndef HFILES_ROBOT_HPP
#define HFILES_ROBOT_HPP

#include <ctime>

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
        inline int          getRobotMaxBattery()    const{return maxBattery;}      // returns robot max battery level
        inline int          getRobotCleanTime()          {return cleanTime;}       // returns robot clean time
        inline float        getRobotBreakOdds()     const{return breakOdds;}       // returns robot break ODDS
        inline time_t       getRobotLastUsed()           {return lastUsed;}        // returns last time the robot was used

        void setRobotStatus(RobotStatus newStatus);     // sets robot status
        void setBatteryLevel(int newBatteryLevel);      // charges robot
        void setLastUsed(time_t newLastUsed);           // sets the last time used

    protected:
        const int robotId;
        const RobotType type;
        const RobotSize size;
        RobotStatus status;
        int batteryLevel;
        const int maxBattery = 100;
        const float breakOdds = 0.25;
        int cleanTime;
        time_t lastUsed;
};

#endif