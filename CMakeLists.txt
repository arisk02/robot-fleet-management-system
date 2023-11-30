cmake_minimum_required(VERSION 3.16)
project(CleaningSystemLib)

find_package(Threads REQUIRED)

include(dependencies.cmake)

add_library(CleaningSystemLib
  
  src/mopper.cpp
  src/robot.cpp
  src/room.cpp
  src/scrubber.cpp
  src/cleaningSystem.cpp
  src/vacuum.cpp
)

target_include_directories(CleaningSystemLib
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(CleaningSystemLib
  fmt::fmt
  Threads::Threads
)

add_subdirectory(app)
