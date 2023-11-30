#include <iostream>
#include <vector>
#include <string>
#include <fmt/core.h>
#include "../src/cleaningSystem.cpp"
#include "../src/logger.cpp"


using namespace std;
using namespace cleaningSys;

int main() {
    // if (argc != 3) {
    //     cout << "Usage: Please enter the number of rooms and the number of robots" << endl;
    //     return 1;
    // }

    cleaningSystem newCleaningSystem;
    fmt::print("Welcome to your Robot Fleet Management System!");
    newCleaningSystem.loggerSetup("log.csv");
    while (true) {
        newCleaningSystem.log();
        fmt::print("Main:\n");
        fmt::print("1. See Robot Status\n");
        fmt::print("2. See Room Status\n");
        fmt::print("3. Clean Room\n");
        fmt::print("4. Quit\n");

        int choice; //potential bug: if user enters a non-integer, the program will crash
        fmt::print("Enter your choice: ");
        cin >> choice;

        if (choice == 1) {
            vector<int> robots;
            for (int i = 1; i < 7; i++){
                robots.push_back(i);
            }
            auto status = newCleaningSystem.queryRobotStatus(robots); //might need an input
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

        } else if (choice == 3) {
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
            fmt::print("Goodbye!\n");
            break;
        } else {
            fmt::print("Invalid choice. Please enter 1, 2, or 3.");
        }
    }

    return 0;
}