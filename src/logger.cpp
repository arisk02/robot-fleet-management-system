#include "hppfiles/logger.hpp"
#include <chrono>
#include <iomanip>
#include <unistd.h> //enables sleep for linux based systems
/*
Logger::Logger(string file, cleaningSys::cleaningSystem& cleanSys){
    filename = file;
    cleanSystem = cleanSys;
    ofstream logFile;
    logFile.open(filename);
    logFile << "Time" << ",";
    vector<string> robotStatusList = cleanSystem.queryRobotStatus();
    vector<string> roomStatusList = cleanSystem.queryRoomStatus();
    for (int id=0; id<robotStatusList.size();id+=3){
        logFile << "Robot " << robotStatusList[id] << " Status" << ",";
        logFile << "Robot " << robotStatusList[id] << " Battery" << ",";
    }
    for (int id=0; id<roomStatusList.size();id+=4){
        logFile << "Room " << roomStatusList[id] << " Cleanliness" << ",";
        if (id + 4 < roomStatusList.size()){
            logFile << "Room " << roomStatusList[id] << " Status" << ",";
        }
        else {
            logFile << "Room " << roomStatusList[id] << " Status\n";
        }
    }
    logFile.close();
}

void Logger::log(){
    ofstream logFile;
    logFile.open(filename, std::ios::out | std::ios::app);
    vector<string> robotStatusList = cleanSystem.queryRobotStatus();
    vector<string> roomStatusList = cleanSystem.queryRoomStatus();
    auto currTime = chrono::system_clock::now();
    auto currTimeT = chrono::system_clock::to_time_t(currTime);
    auto curr_local = localtime(&currTimeT);
    logFile << put_time(curr_local, "%c") << ",";
    for (int i=1; i<robotStatusList.size();i+=3){
        logFile << robotStatusList[i] << "," << robotStatusList[i+1] << ",";
    }
    for (int i=2; i<roomStatusList.size(); i+=4){
        if (i + 4 < roomStatusList.size()){
            logFile << roomStatusList[i] << "," << roomStatusList[i+1] << ",";
        }
        else {
            logFile << roomStatusList[i] << "," << roomStatusList[i+1] << "\n";
        }
    }
    logFile.close();
}
*/