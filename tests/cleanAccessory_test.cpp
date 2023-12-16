#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <unistd.h>
#include <fmt/core.h>

#include "hppfiles/cleaningSystem.hpp"

using namespace cleaningSys;
using namespace std;
using Catch::Matchers::ContainsSubstring;

cleaningSystem newCleaningSystem {};

TEST_CASE("Query robot status"){

    vector<string> status;
    vector<string> status2;

    SECTION("Query select IDs"){ // Test query robot status basic functionality

        vector<int> robotId = {0,1,2};
        status = newCleaningSystem.queryRobotStatus(robotId); // Query robots with select robot IDs

        REQUIRE( status.size() == 9 );
        REQUIRE( status[0] == "0" );
        REQUIRE( status[1] == "Availible" );
        REQUIRE( status[2] == "100" );
        REQUIRE_THROWS_AS( status.at(9), std::out_of_range ); // Test end point
    }

    SECTION("Query all robots"){

        status2 = newCleaningSystem.queryRobotStatus(); // Query all robots

        REQUIRE( status2.size() == 54 );
        REQUIRE( status2[51] == "17" );
        REQUIRE( status2[52] == "Availible" );
        REQUIRE( status2[53] == "100" );
        REQUIRE_THROWS_AS( status.at(54), std::out_of_range );
    }
    SECTION("Query robot that does not exist"){ // There is no robot with ID 18, should throw an exception

        REQUIRE_THROWS_WITH(newCleaningSystem.queryRobotStatus({18}), ContainsSubstring("key not found"));
        REQUIRE_THROWS_WITH(newCleaningSystem.queryRoomStatus({1,18}),  ContainsSubstring("key not found"));
    }
}

TEST_CASE("Query Room Status"){

    vector<string> status;
    vector<string> status2;

    SECTION("Query select IDs"){ // Test query room status basic functionality

        vector<int> roomId = {0,1,2};
        status = newCleaningSystem.queryRoomStatus(roomId); // Query rooms with select room IDS

        REQUIRE( status.size() == 12 );
        REQUIRE( status[0] == "0" );
        REQUIRE( status[1] == "small" );
        REQUIRE( status[2] == "Clean" );
        REQUIRE( status[3] == "not occupied by robot" );
        REQUIRE_THROWS_AS( status.at(12), std::out_of_range );
    }
    SECTION("Query all rooms"){

        status2 = newCleaningSystem.queryRoomStatus(); // Query all rooms

        REQUIRE( status2.size() == 24 ) ;
        REQUIRE( status2[20] == "5" );
        REQUIRE( status2[21] == "large" );
        REQUIRE( status2[22] == "Clean" );
        REQUIRE( status2[23] == "not occupied by robot" );
        REQUIRE_THROWS_AS( status.at(24), std::out_of_range );   
    }
    SECTION("Query room that does not exist"){ // There is no room with ID 8, should throw an exception

        REQUIRE_THROWS_WITH(newCleaningSystem.queryRoomStatus({8}),  ContainsSubstring("key not found"));
        REQUIRE_THROWS_WITH(newCleaningSystem.queryRoomStatus({1,8}),  ContainsSubstring("key not found")); // Make sure still works if one exists
    }
}

TEST_CASE("Validate IDs"){ // Test the validate ID functions
    vector<string> status;

    SECTION("Validate Robot IDs"){
        status = newCleaningSystem.queryRobotStatus();

        CHECK( newCleaningSystem.validateRobotIDs({1,2}) == true ); // These IDs exist 
        CHECK( newCleaningSystem.validateRobotIDs({18,19}) == false ); // These do not
    }

    SECTION("Validate Room IDs"){
        status = newCleaningSystem.queryRoomStatus();

        CHECK( newCleaningSystem.validateRoomIDs({1,2}) == true ); // These exist
        CHECK( newCleaningSystem.validateRoomIDs({6,7}) == false ); // These do not
    }
}
