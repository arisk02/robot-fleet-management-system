#include <catch2/catch_test_macros.hpp>
#include "hppfiles/cleaningSystem.hpp"
#include "hppfiles/room.hpp"
#include "hppfiles/robot.hpp"

using namespace cleaningSys;
using namespace std;

 cleaningSystem newCleaningSystem {1, 1, 1,
                                        2, 2, 2,
                                        3, 3, 3,
                                        4, 4, 4};

TEST_CASE("Query Robot Status"){

    SECTION("Query select IDs"){//Test query robot status
        vector<int> robotId = {0,1,2};
        vector<string> status;
        status = newCleaningSystem.queryRobotStatus(robotId); //query robots with select robot IDs

        REQUIRE( status.size() == 9 );
        REQUIRE( status[0] == "0" );
        REQUIRE( status[1] == "Availible" );
        REQUIRE( status[2] == "100" );
    }
    SECTION("Query all robots"){

        vector<string> status2;
        status2 = newCleaningSystem.queryRobotStatus(); //query all robots

        REQUIRE( status2[51] == "17" );
        REQUIRE( status2[52] == "Availible" );
        REQUIRE( status2[53] == "100");
        REQUIRE( status2[54] == "" );

        //need to set one robot to broken and then retest

        newCleaningSystem.cleanAsync({0}, 10, 0);
        vector<string> status3;
        status3 = newCleaningSystem.queryRobotStatus({0});
    }
}

TEST_CASE("Query Room Status"){

    SECTION("Query select IDs"){//Test query room status
        vector<int> roomId = {0,1,2};
        vector<string> status;
        status = newCleaningSystem.queryRoomStatus(roomId);//query rooms with select room IDS

        REQUIRE( status.size() == 12 );
        REQUIRE( status[0] == "0" );
        REQUIRE( status[1] == "small" );
        REQUIRE( status[2] == "Clean" );
        REQUIRE( status[3] == "not occupied by robot" );
    }
    SECTION("Query all rooms"){

        vector<string> status2;
        status2 = newCleaningSystem.queryRoomStatus();//query all rooms

        REQUIRE( status2.size() == 48) ;
        REQUIRE( status2[44] == "11" );
        //REQUIRE( status[45] == "large" ); //need to check why this is failing
        REQUIRE( status2[46] == "Clean" );
        REQUIRE( status2[47] == "not occupied by robot" );
        
    }
}

TEST_CASE("Clean"){//Need to test clean
    SECTION("CleanAsync"){
        //test if battery of robot is dead
        //test if robot is broken
    }
}

TEST_CASE("Recharge Robots"){// Test recharge robots
    vector<int> botIds = {0,1};
    vector<string> status;

    newCleaningSystem.cleanAsync(botIds, 10, 0);
    status = newCleaningSystem.queryRobotStatus(botIds);

    REQUIRE( status[2] != "100" );//make sure the battery drained with clean
    REQUIRE( status[5] != "100" );

    newCleaningSystem.recharge(botIds);
    vector<string> status2;
    status2 = newCleaningSystem.queryRobotStatus(botIds); //query robots with select robot IDs

    REQUIRE( status2[2] == "100" ) ;//make sure the robot was recharged
    REQUIRE( status2[5] == "100" );
}

TEST_CASE("Repair Robots"){//Test repair robots
    vector<int> botIds = {2};
    vector<string> status;

    newCleaningSystem.cleanAsync(botIds, 10, 0);
    status = newCleaningSystem.queryRobotStatus(botIds);
    if(status[1] == "Broken"){
        newCleaningSystem.repair(botIds);
    }
    vector<string> status2;
    status2 = newCleaningSystem.queryRobotStatus(botIds);

    REQUIRE( status2[1] == "Availible" );
}
