#include <iostream>
#include <vector>
#include <string>
#include "../src/cleaningSystem.cpp"

using namespace std;
using namespace cleaningSys;

int main() {
    // if (argc != 3) {
    //     cout << "Usage: Please enter the number of rooms and the number of robots" << endl;
    //     return 1;
    // }

    cleaningSystem newCleaningSystem;
    cout << "Welcome to your Robot Fleet Management System!" << endl;
    while (true) {
        cout << "Main:" << endl;
        cout << "1. See Robot Status" << endl;
        cout << "2. See Room Status" << endl;
        cout << "3. Quit" << endl;

        int choice; //potential bug: if user enters a non-integer, the program will crash
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            vector<int> robots;
            for (int i = 1; i < 8; i++){
                robots.push_back(i);
            }
            auto status = newCleaningSystem.queryRobotStatus(robots); //might need an input
            int itemPerRobot = 3;
            for (int i = 0; i < status.size(); i += itemPerRobot) {
                cout << "Robot " << status[i] << " is " << status[i + 1] << " and is at the battery level" << status[i + 2] << endl;
            }

            cout << "Type anything to return to the main menu: ";
            string val;
            cin >> val;

        } else if (choice == 2) {
            vector<int> rooms;
            rooms.push_back(1);
            auto status = newCleaningSystem.queryRoomStatus(rooms);
            int itemPerRoom = 3;
            for (int i = 0; i < status.size(); i += itemPerRoom) {
                cout << "Room " << status[i] << " is " << status[i + 1] << " and is " << status[i + 2] << endl;
            }

            cout << "Type anything to return to the main menu: ";
            string val;
            cin >> val;

        } else if (choice == 3) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }

    return 0;
}