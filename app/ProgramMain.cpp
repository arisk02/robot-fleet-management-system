#include <iostream>
#include <vector>
#include <string>
#include <fmt/core.h>
#include "../src/cleaningSystem.cpp"
#include <sstream>


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

// Create custom split() function.  
std::vector<int> customSplit(const std::string& input) {
    std::vector<int> result;
    std::istringstream iss(input);

    int id;
    while (iss >> id) {
        result.push_back(id);
    }

    return result;
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

            string robotsids; //potential bug: if user enters a non-integer, the program will crash
            fmt::print("Enter the ids of the robots whose status you want separated by a space: ");
            cin.ignore();
            getline(cin, robotsids);
            robots = customSplit(robotsids);

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

            string roomsids; //potential bug: if user enters a non-integer, the program will crash
            fmt::print("Enter the ids of the rooms whose status you want separated by a space: ");
            cin.ignore();
            getline(cin, roomsids);
            rooms = customSplit(roomsids);

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

            string robotsids; //potential bug: if user enters a non-integer, the program will crash
            fmt::print("Enter the ids of the robots you want to assign to that room: ");
            cin.ignore();
            getline(cin, robotsids);
            robots = customSplit(robotsids);

            newCleaningSystem.clean(roomid, robots);
            
            fmt::print("Type anything to return to the main menu: ");
            string val;
            cin >> val;

        } else if (choice == 4) {
            vector<int> robots;

            string robotsids; //potential bug: if user enters a non-integer, the program will crash
            fmt::print("Enter the ids of the robots you want to fix: ");
            cin.ignore();
            getline(cin, robotsids);
            robots = customSplit(robotsids);

            while(true) {
                fmt::print("Please select a command:\n");
                fmt::print("1. Charge robot\n");
                fmt::print("2. Repair robot\n");
                    
                int choice;
                cin >> choice;
                if (choice == 1) {
                    newCleaningSystem.recharge(robots);
                    fmt::print("Successfully recharged robot. Returning to main menu.\n");
                    break;
                }
                else if (choice == 2) {
                    newCleaningSystem.repair(robots);
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






        
        

       
            

     