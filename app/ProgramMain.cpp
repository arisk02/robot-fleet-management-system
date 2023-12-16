#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <fmt/core.h>
#include <sstream>
#include <filesystem>
#include "../src/cleaningSystem.cpp"


using namespace std;
using namespace cleaningSys;

// Create custom split() function.  
vector<int> customSplit(string choice, string er) {
    string userInput;
    vector<int> numbers;

    while (true) {
        fmt::print("{}", choice);
        getline(cin, userInput);

        istringstream iss(userInput);
        int num;

        while (iss >> num) {
            numbers.push_back(num);
        }

        if (iss.fail() && !iss.eof()) {
            fmt::print("{}", er);
            numbers.clear();  // Clear the vector for invalid input
        } else {
            break;  // Exit the loop if input is valid
        }
    }
    return numbers;
}



int main() {

    
    fmt::print("Welcome to your Robot Fleet Management System!");

    cleaningSystem newCleaningSystem;

    newCleaningSystem.loggerSetup("../../config_and_log/log.csv");
    while (true) {
        newCleaningSystem.log();
        fmt::print("\nMain:");
        fmt::print("\n1. See Robot Status");
        fmt::print("\n2. See Room Status");
        fmt::print("\n3. Clean Room");
        fmt::print("\n4. Fix Robot");
        fmt::print("\n5. Quit");

        int choice; //potential bug: if user enters a non-integer, the program will crash
        fmt::print("\nEnter your choice: ");
        cin >> choice;

        if (choice == 1) {

            cin.ignore();

            while (true) {

                vector<int> robots = customSplit("\nEnter the ids of the robots whose status you want separated by a space, or -1 to show all: ",
                                                "\nInvalid input: contains a non-integer. Robot ids are integers.");

                vector<string> status;

                if (robots[0] == -1 && robots.size() == 1) {
                    status = newCleaningSystem.queryRobotStatus();
                }

                else if (!newCleaningSystem.validateRobotIDs(robots)){
                    fmt::print("\nInvalid input: one or more of the input IDs do not exist.");
                    continue;
                }

                else {
                    status = newCleaningSystem.queryRobotStatus(robots);
                }

                int itemPerRobot = 3;

                for (int i = 0; i < status.size(); i += itemPerRobot) {
                    fmt::print("\nRobot {} is {} and is at the battery level {}", status[i], status[i + 1], status[i + 2]);
                }

                fmt::print("\nType anything to return to the main menu: ");
                string val;
                cin >> val;
                break;
            }

        } else if (choice == 2) {

            cin.ignore();

            while (true) {

                vector<int> rooms = customSplit("\nEnter the ids of the rooms whose status you want separated by a space, or -1 to show all: ",
                                                "\nInvalid input: contains a non-integer. Room ids are integers.");

                vector<string> status;

                if (rooms[0] == -1 && rooms.size() == 1) {
                    status = newCleaningSystem.queryRoomStatus();
                }

                else if (!newCleaningSystem.validateRoomIDs(rooms)){
                    fmt::print("\nInvalid input: one or more of the input IDs do not exist.");
                    continue;
                }

                else {
                    status = newCleaningSystem.queryRoomStatus(rooms);
                }

                int itemPerRoom = 4;

                for (int i = 0; i < status.size(); i += itemPerRoom) {
                    fmt::print("\nRoom {} is {} and is {}", status[i], status[i + 1], status[i + 2]);
                }

                fmt::print("\nType anything to return to the main menu: ");
                string val;
                cin >> val;
                break;
            }

        } else if (choice == 3) {

            cin.ignore();

            vector<int> robots;
            vector<int> roomid;
            
            while(true) {

                roomid = customSplit("\nEnter the id of the room you want to clean: ",
                                    "\nInvalid input: contains a non-integer. Room ids are integers.");

                if (roomid.size() != 1) {
                    fmt::print("\nYou can only input 1 room to clean. ");
                    continue;
                }

                if (!newCleaningSystem.validateRoomIDs(roomid)) {
                    fmt::print("\nInvalid input: input ID does not exist.");
                    continue;
                }

                while (true) {

                    robots = customSplit("\nEnter the ids of the robots you want to assign to that room: ",
                                        "\nInvalid input: contains a non-integer. Robot ids are integers.");

                    if (!newCleaningSystem.validateRobotIDs(robots)){
                            fmt::print("\nInvalid input: one or more of the input IDs do not exist.");
                            continue;
                    }

                    break;

                }

                newCleaningSystem.clean(roomid[0], robots);
                fmt::print("\nType anything to return to the main menu: ");
                string val;
                cin >> val;
                break;
            }

        } else if (choice == 4) {

            cin.ignore();

            while(true) {

                vector<int> robots = customSplit("\nEnter the ids of the robots you want to fix: ",
                                                "\nInvalid input: contains a non-integer. Robot ids are integers.");

                if (!newCleaningSystem.validateRobotIDs(robots)){
                    fmt::print("\nInvalid input: one or more of the input IDs do not exist.");
                    continue;
                }

                while(true) {
                    
                    vector<int> choic = customSplit("\nPlease select a command:\n1. Charge robot\n2. Repair robot\nCommand: ",
                                                "\nInvalid input: contains a non-integer. Choice has to be either 1 or 2.");

                    if (choic.size() != 1) {
                        fmt::print("\nInvalid input: input has to be of size 1.");
                        continue;
                    }

                    int wht = choic[0];

                    if (wht == 1) {
                        newCleaningSystem.recharge(robots);
                        fmt::print("\nSuccessfully recharged robots.");
                        break;
                    }
                    else if (wht == 2) {
                        newCleaningSystem.repair(robots);
                        fmt::print("\nSuccessfully repaired robots.");
                        break;
                    }
                    else {
                        fmt::print("\nInvalid choice. Please enter 1 or 2.");
                    }
                }

                fmt::print("\nType anything to return to the main menu: ");
                string val;
                cin >> val;
                break;
            }

        } else if (choice == 5) {
            fmt::print("\nGoodbye!");
            break;
        }
        
        else {
            fmt::print("\nInvalid choice. Please enter 1, 2, 3, 4 or 5");
        }

    }

    return 0;
}