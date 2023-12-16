#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <unistd.h>

#include "hppfiles/cleaningSystem.hpp"

using namespace cleaningSys;
using namespace std;

cleaningSystem newCleaningSystem {};

TEST_CASE("Recharge Robots"){ // Test recharge robots

    vector<int> botIds = {4,5};
    vector<string> status;
    vector<string> status2;

    newCleaningSystem.clean(1, botIds); // Clean room one with robots 4 and 5

    WARN( "Please allow the clean function to execute (Testing Recharge)" );
    sleep(17); // Allow them to finish cleaning
    WARN( "Clean function has finished (Testing Recharge)" );

    newCleaningSystem.recharge(botIds); // Recharge robots 4 and 5

    status2 = newCleaningSystem.queryRobotStatus(botIds); // Query robots with select robot IDs

    REQUIRE( status2[2] == "100" ) ; // Make sure the robots were recharged
    REQUIRE( status2[5] == "100" ); // Broken or not they should now be at 100

}

TEST_CASE("Repair Robots"){ // Test repair robots

    vector<string> status;
    vector<string> status2;

    newCleaningSystem.clean(0, {11}); // Clean room 0 with robot 11

    WARN( "Please allow the clean function to execute (Testing Repair)" );
    sleep(17); // Allow them to finish cleaning
    WARN( "Clean function has finished (Testing Repair)" );

    status = newCleaningSystem.queryRobotStatus({11});

    if(status[1] == "Broken"){ // If it breaks during cleaning, fix it
        newCleaningSystem.repair({11});
    }

    status2 = newCleaningSystem.queryRobotStatus({11});

    REQUIRE( status2[1] == "Availible" ); // Should always return available
}