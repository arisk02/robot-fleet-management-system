#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <fmt/core.h>
#include <sstream>
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

// Create custom split() function.  
std::vector<int> customSplit(const std::string& input) {
    std::vector<int> result;
    std::istringstream iss(input);

    int id;
    while (iss >> id) {
        result.push_back(id);
    }

    if (!iss.eof()) {
        result.clear(); // Clear the result vector
        result.push_back(-403); // return -1 to indicate an error
    }

    return result;
}



int main() {
    
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

    newCleaningSystem.loggerSetup("log.csv");
    while (true) {
        newCleaningSystem.log();
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
            string robotsids; 
            bool truth = true;
            while (truth) {
                fmt::print("Enter the ids of the robots whose status you want separated by a space, or -1 to show all: ");
                cin.ignore();
                getline(cin, robotsids);
                robots = customSplit(robotsids);

                vector<string> status;

                if (robots[0] == -1) {
                    status = newCleaningSystem.queryRobotStatus();
                    truth = false;
                }
                else if (robots[0]== -403) {
                    fmt::print("Please only enter valid ids! \n");
                }
                else {
                    status = newCleaningSystem.queryRobotStatus(robots);
                    truth = false;
                }
            

                int itemPerRobot = 3;
                for (int i = 0; i < status.size(); i += itemPerRobot) {
                    fmt::print("Robot {} is {} and is at the battery level {}\n", status[i], status[i + 1], status[i + 2]);
                }

                fmt::print("Type anything to return to the main menu: ");
                string val;
                cin >> val;
            }

        } else if (choice == 2) {
            vector<int> rooms;
            bool truth = true;
            string roomsids; 
            
            while(truth) {
                fmt::print("Enter the ids of the rooms whose status you want separated by a space, or -1 to show all: ");
                cin.ignore();
                getline(cin, roomsids);
                rooms = customSplit(roomsids);

                vector<string> status;

                if (rooms[0] == -1) {
                    status = newCleaningSystem.queryRoomStatus();
                    truth = false;
                }
                else if (rooms[0]== -403) {
                        fmt::print("Please only enter valid ids! \n");
                        continue;
                    }
                else {
                    status = newCleaningSystem.queryRoomStatus(rooms);
                    truth = false;
                }

                int itemPerRoom = 4;
                for (int i = 0; i < status.size(); i += itemPerRoom) {
                    fmt::print("Room {} is {} and is {}\n", status[i], status[i + 1], status[i + 2]);
                }

                fmt::print("Type anything to return to the main menu: ");
                string val;
                cin >> val;
            }
        } else if (choice == 3) { 
            int roomid; 
            bool truth = true;
            
            while(truth) {
                cout << "Enter the id of the room you want to clean: ";
                cin >> roomid;

                vector<int> robots;

                string robotsids; 
                fmt::print("Enter the ids of the robots you want to assign to that room: ");
                cin.ignore();
                getline(cin, robotsids);
                robots = customSplit(robotsids);
                if (robots[0] != -403) {
                    truth = false;
                }
                else {
                    fmt::print("Please only enter valid ids! \n");
                    continue;
                }

                newCleaningSystem.clean(roomid, robots);
                fmt::print("Type anything to return to the main menu: ");
                string val;
                cin >> val;
            }

        } else if (choice == 4) {
            vector<int> robots;
            int maxID = newCleaningSystem.getRobotCount();
            string robotsids; 
            bool loop = true;
            while(true) {
                fmt::print("Enter the ids of the robots you want to fix: "); //returning to main todo
                cin.ignore();
                getline(cin, robotsids);
                robots = customSplit(robotsids);
                for (auto id : robots) {
                    bool truth = true;
                    if (id != -403 ) {
                        if (id < 0) {
                            break;
                        }
                        else if(id > maxID) {
                            fmt::print("One or more IDs were invalid. Try again.\n");
                            loop = true;
                            break;
                        }
                        else {
                            loop = false;
                        }
                    }
                    else {
                        fmt::print("Please only enter digits. \n");
                        break;
                    }
                }
                if (loop == false) {
                    break;
                }
            }
                    
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






        
        

       
            

     