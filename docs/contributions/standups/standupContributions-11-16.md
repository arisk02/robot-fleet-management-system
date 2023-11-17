# 11/16/23 Standup Contributions

## Bereket
- Updated room to dynamically select the type of cleaning required (room class branch)
- Updated the command line interface to support the added features like rechange and repair (update-main branch)

## Ethan
- Researched concurrency in c++, specificanlly the async function.
- Updated sequence diagram for clean_room function with refined plan for that function given better knowledge on concurrency. I now have a plan for how I will be implementing the function with async

## Caitlin
- Implemented fixRobot function
- Implemented chargeRobot function

## Aris
- Fixed virtual class and subclass issues
  - changed vector<Robot> to vector<Robot*> in header and all functions
  - dynamically allocated Robots
- Created a cleaningSystem constructor that takes in parameters for a custom fleet and building size
- Reviewed implementation of fixRobot and chargeRobot and discussed with the team on how to integrate this with programMain
- Researched and raised questions on how our robots and rooms are stored, advised on changing vector storage to dictionary storage for better runtime on large fleets
