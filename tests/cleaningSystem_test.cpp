#include <catch2/catch_test_macros.hpp>
#include "hppfiles/cleaningSystem.hpp"
#include "hppfiles/room.hpp"
#include "hppfiles/robot.hpp"

using namespace cleaningSys;
using namespace std;

TEST_CASE("Cleaning System Test"){

    vector<Robot*> robots;
    vector<Room> rooms;

    rooms.push_back(Room(Room::Size::medium, true, 1));
    rooms.push_back(Room(Room::Size::medium, true, 1));
    rooms.push_back(Room(Room::Size::medium, true, 1));
    robots.push_back(new Mopper(RobotSize::LARGE, 2));
    robots.push_back(new Mopper(RobotSize::MEDIUM, 3));
    robots.push_back(new Mopper(RobotSize::SMALL, 4));
    robots.push_back(new Vacuum(RobotSize::MEDIUM, 5));
    robots.push_back(new Scrubber(RobotSize::MEDIUM, 6));
    robots.push_back(new Mopper(RobotSize::MEDIUM, 7));

    /*SECTION("Get Robots"){
        vector<int> Ids = {2,3,4};
        vector<Robot*> requiredRobots = robots.getRobots(Ids);
        REQUIRE (requiredRobots.size() == 3);
        REQUIRE (requiredRobots.at(0)->getRobotId() == 2);
    }*/
    
    SECTION("Query Robot Status"){

    }

    SECTION("Query Room Status"){

    }

    SECTION("Recharge Robots"){

    }

    SECTION("Repair Robots"){

    }
}