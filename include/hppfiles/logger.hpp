#ifndef HPPFILES_LOGGER_HPP
#define HPPFILES_LOGGER_HPP
#include "cleaningSystem.hpp"
#include <string>
#include <fstream>
#include <vector>
#include <future>

using namespace std;
class Logger
{
private:
    cleaningSys::cleaningSystem cleanSystem;
    string filename;


public:
    Logger(string filename, cleaningSys::cleaningSystem cleanSystem);
    void loggerAsync();
};

#endif