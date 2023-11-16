#include <iostream>
#include <vector>
#include <string>
#include <fmt/core.h>
#include "../src/cleaningSystem.cpp"


using namespace std;
using namespace cleaningSys;

int main() {
    // if (argc != 3) {
    //     cout << "Usage: Please enter the number of rooms and the number of robots" << endl;
    //     return 1;
    // }

    cleaningSystem newCleaningSystem;
    fmt::print("Welcome to your Robot Fleet Management System!");
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
            for (int i = 1; i < 8; i++){
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
            while(true) {//having a function that returns robot count would be nice here
                fmt::print("Please enter the id of the robot: \n");
                int robotId; //potential bug: if user enters a non-integer, the program will crash
                cin >> robotId;
                //TODO: logic to handle bad input
                break;
            }
            vector<int> vec;
            vec.push_back(robotId); // turn this to for loop for multiple ids
            vector<Robot*> bots = newCleaningSystem.getRobots(vec);
                while(true) {
                    fmt::print("Please select a command:\n");
                    fmt::print("1. Charge robot\n");
                    fmt::print("2. Repair robot\n");
                    
                    int choice;
                    cin >> choice;
                    if (choice == 1) {
                        for (auto robot: bots) {
                            robot.chargeRobot();
                        }
                        fmt::print("Successfully recharged robot. Returning to main menu.\n");
                    }
                    else if (choice == 2) {
                       for (auto robot: bots) {
                            robot.fixRobot();
                        }
                        fmt::print("Successfully repaired robot. Returning to main menu. \n");
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






        
        

       
            

     