#include <iostream>
#include <vector>
#include <string>
#include <fmt/core.h>
#include "../src/cleaningSystem.cpp"


using namespace std;
using namespace cleaningSys;

cleaningSystem create(int def,  int smallScrubbers, int mediumScrubbers, int largeScrubbers,
                                int smallVacuums, int mediumVacuums, int largeVacuums,
                                int smallMoppers, int mediumMoppers, int largeMoppers,
                                int smallRooms, int mediumRooms, int largeRooms) {
    if (def == 1) {
        return cleaningSystem(smallScrubbers, mediumScrubbers, largeScrubbers,
                              smallVacuums, mediumVacuums, largeVacuums,
                              smallMoppers, mediumMoppers, largeMoppers,
                              smallRooms, mediumRooms, largeRooms);
    }
    else {
        return cleaningSystem();
    }
}

int main() {
    // if (argc != 3) {
    //     cout << "Usage: Please enter the number of rooms and the number of robots" << endl;
    //     return 1;
    // }
    fmt::print("Welcome to your Robot Fleet Management System!\n");
    fmt::print("Input 0 to create a fleet of default size, or 1 for custom size:\n");

    int choice;
    cin >> choice;

    int smallScrubbers;
    int mediumScrubbers;
    int largeScrubbers;

    int smallVacuums;
    int mediumVacuums;
    int largeVacuums;

    int smallMoppers;
    int mediumMoppers;
    int largeMoppers;

    int smallRooms;
    int mediumRooms;
    int largeRooms;


    if (choice == 1) {
        fmt::print("Desired number of small Scrubbers:\n");
        cin >> smallScrubbers;
        fmt::print("Desired number of medium Scrubbers:\n");
        cin >> mediumScrubbers;
        fmt::print("Desired number of large Scrubbers:\n");
        cin >> largeScrubbers;
        
        fmt::print("Desired number of small Vacuums:\n");
        cin >> smallVacuums;
        fmt::print("Desired number of medium Vacuums:\n");
        cin >> mediumVacuums;
        fmt::print("Desired number of large Vacuums:\n");
        cin >> largeVacuums;

        fmt::print("Desired number of small Moppers:\n");
        cin >> smallMoppers;
        fmt::print("Desired number of medium Moppers:\n");
        cin >> mediumMoppers;
        fmt::print("Desired number of large Moppers:\n");
        int largeMoppers;
        cin >> largeMoppers;

        fmt::print("Desired number of small Rooms:\n");
        cin >> smallRooms;
        fmt::print("Desired number of medium Rooms:\n");
        cin >> mediumRooms;
        fmt::print("Desired number of large Rooms:\n");
        cin >> largeRooms;
    }

    cleaningSystem newCleaningSystem = create(choice, smallScrubbers, mediumScrubbers, largeScrubbers,
                                                          smallVacuums, mediumVacuums, largeVacuums,
                                                          smallMoppers, mediumMoppers, largeMoppers,
                                                          smallRooms, mediumRooms, largeRooms);

    fmt::print("Welcome to your Robot Fleet Management System!\n");
    while (true) {
        fmt::print("Main:\n");
        fmt::print("1. See Robot Status\n");
        fmt::print("2. See Room Status\n");
        fmt::print("3. Clean Room\n");
        fmt::print("4. Fix Robot\n");
        fmt::print("5. Quit\n");

        int choice; //potential bug: if user enters a non-integer, the program will crash
        fmt::print("Enter your choice: ");
        cin >> choice;

        if (choice == 1) {
            vector<int> robots;
            for (int i = 1; i < 7; i++){
                robots.push_back(i);
            }
            auto status = newCleaningSystem.queryRobotStatus(robots); 
            int itemPerRobot = 3;
            for (int i = 0; i < status.size(); i += itemPerRobot) {
                fmt::print("Robot {} is {} and is at the battery level {}\n", status[i], status[i + 1], status[i + 2]);
            }

            fmt::print("Type anything to return to the main menu: ");
            string val;
            cin >> val;

        } else if (choice == 2) {
            vector<int> rooms;
            rooms.push_back(1);
            auto status = newCleaningSystem.queryRoomStatus(rooms);
            int itemPerRoom = 4;
            for (int i = 0; i < status.size(); i += itemPerRoom) {
                fmt::print("Room {} is {} and is {}\n", status[i], status[i + 1], status[i + 2]);
            }

            fmt::print("Type anything to return to the main menu: ");
            string val;
            cin >> val;

        } else if (choice == 3) { //will probably need room size and type of cleaning at min and type of robot
            int roomid; //potential bug: if user enters a non-integer, the program will crash
            cout << "Enter the id of the room you want to clean: ";
            cin >> roomid;

            vector<int> robots;

            while(true){
                int robotsids; //potential bug: if user enters a non-integer, the program will crash
                fmt::print("Enter the id of the robot you want to assign: ");
                cin >> robotsids;
                robots.push_back(robotsids);
                int st; //potential bug: if user enters a non-integer, the program will crash
                fmt::print("If you want to assign more robots, enter 1, otherwise 0: ");
                cin >> st;
                if (st == 0){
                    break;
                }
            }

            newCleaningSystem.clean(roomid, robots);
            
            fmt::print("Type anything to return to the main menu: ");
            string val;
            cin >> val;

        } else if (choice == 4) {
            int robotId; //potential bug: if user enters a non-integer, the program will crash
            vector<int> vec;

            while(true) {//having a function that returns robot count would be nice here
                fmt::print("Please enter the ids of the robots one at a time. Enter -1 if finished: \n");
                cin >> robotId;
                if (robotId < 0) {
                    break;
                }
                vec.push_back(robotId);
                //TODO: logic to handle bad input
            }
            while(true) {
                fmt::print("Please select a command:\n");
                fmt::print("1. Charge robot\n");
                fmt::print("2. Repair robot\n");
                    
                int choice;
                cin >> choice;
                if (choice == 1) {
                    newCleaningSystem.recharge(vec);
                    fmt::print("Successfully recharged robot. Returning to main menu.\n");
                    break;
                }
                else if (choice == 2) {
                    newCleaningSystem.repair(vec);
                    fmt::print("Successfully repaired robot. Returning to main menu. \n");
                    break;
                }
                else {
                        fmt::print("Bad input.\n");
                }
            }
        } else if (choice == 5) {
            fmt::print("Goodbye!\n");
            break;
        } else {
            fmt::print("Invalid choice. Please enter 1, 2, or 3.");
        }
    }

    return 0;
}






        
        

       
            

     