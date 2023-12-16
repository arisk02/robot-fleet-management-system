#include <catch2/catch_test_macros.hpp>
#include <unistd.h>
#include "hppfiles/cleaningSystem.hpp"

using namespace cleaningSys;
using namespace std;

cleaningSystem newCleaningSystem {};

TEST_CASE("Clean"){ // Test clean functionality

    vector<string> status;
    vector<string> status2;

    vector<string> statusRoom;
    vector<string> statusRoom2;
    vector<string> statusRobot;
    vector<string> statusRobot2;
    vector<string> statusDifRobot;

    SECTION("Robot status after solo clean"){

        newCleaningSystem.clean(0, {5});
        status = newCleaningSystem.queryRobotStatus({5});

        if(status[1] != "Broken"){

            REQUIRE( status[1] == "Cleaning" ); // Require status to be cleaning at first
        }
        
        //bot size = 30 - room size = 500 - cleaning time = 500/30 = 16
        
        WARN("Please allow time for the clean function to execute");
        sleep(17); // allow time for clean
        WARN("Clean function has finished");

        status2 = newCleaningSystem.queryRobotStatus({5});

        if(status2[1] != "Broken"){ // If robot did not break during cleaning

            REQUIRE( status2[0] == "5" ); // robot with id 5 should now be available with a correctly drained battery
            REQUIRE( status2[1] == "Availible" );
            REQUIRE( status2[2] == "84");
        }
        else{

            REQUIRE( status2[1] == "Broken" ); // If it did break during cleaning - status should be broken
        }
    }

    SECTION("Room status after one robot clean"){

        newCleaningSystem.clean(0, {4});
        statusRoom = newCleaningSystem.queryRoomStatus({0});
        statusRobot = newCleaningSystem.queryRobotStatus({4});

        if(statusRobot[1] != "Broken"){

            REQUIRE( statusRoom[3] == "occupied by robot" ); // Make sure the robot is in the room
            REQUIRE( statusRoom[2] == "Dirty"); // Room should have been set to dirty

            newCleaningSystem.clean(0, {11}); // Try to clean the same room with a different robot
            statusDifRobot = newCleaningSystem.queryRobotStatus({11});

            REQUIRE( statusDifRobot[1] == "Availible" ); // Robot 5 should not have been allowed to start cleaning 
        }

        WARN("Please allow time for the clean function to execute"); // Allow the function to run for appropriate time
        sleep(17);
        WARN("Clean function has finished");

        statusRobot2 = newCleaningSystem.queryRobotStatus({4});
        statusRoom2 = newCleaningSystem.queryRoomStatus({0});

        if(statusRobot2[1] != "Broken"){
        
            REQUIRE( statusRoom2[0] == "0" );
            REQUIRE( statusRoom2[1] == "small" );
            REQUIRE( statusRoom2[2] == "Clean" );
            REQUIRE( statusRoom2[3] == "not occupied by robot" );
        }
        else{

            REQUIRE( statusRoom2[2] == "Dirty" );
        }
    }

    SECTION("Robot status after multiple robot clean"){

        newCleaningSystem.clean(1, {10, 11});
        status = newCleaningSystem.queryRobotStatus({10, 11});

        if (status[1] != "Broken" && status[4] != "Broken"){
            REQUIRE( status[1] == "Cleaning" ); // If neither of them are broken they should be cleaning
            REQUIRE( status[4] == "Cleaning" );
        }  

        WARN("Please allow time for the clean function to execute");
        sleep(17); // Allow time for clean
        WARN("Clean function has finished"); 

        status2 = newCleaningSystem.queryRobotStatus({10,11});

        if (status2[1] == "Broken"){ // If one robot breaks that robot should be set to broken and the other to available with no battery drain

            REQUIRE( status2[1] == "Broken" ); 
            REQUIRE( status2[4] == "Availible" );
        }
        else if(status2[4] == "Broken"){
            
            REQUIRE( status2[1] == "Availible" );
            REQUIRE( status2[4] == "Broken" );
        }
        else{ // If neither of the robots break

            REQUIRE( status2[0] == "10" ); // Robot with id 10 should now be available with a correctly drained battery
            REQUIRE( status2[1] == "Availible" );
            REQUIRE( status2[2] == "84");
            
            REQUIRE( status2[3] == "11" ); // Robot with id 11 should now be available with a correctly drained battery
            REQUIRE( status2[4] == "Availible" );
            REQUIRE( status2[5] == "84");
        }
    }
}






