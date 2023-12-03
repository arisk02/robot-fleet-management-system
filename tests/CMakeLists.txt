find_package(Catch2 3 REQUIRED)

IF (${Catch2_FOUND})
    MESSAGE(STATUS "Found Catch2")
ELSE (${Catch2_FOUND})
    MESSAGE(STATUS "Cound not find Catch2. Check to make sure its installed on your system!")
ENDIF (${Catch2_FOUND})

add_executable(cleaningSystem_test cleaningSystem_test.cpp)

target_compile_features(cleaningSystem_test PRIVATE cxx_std_20)

target_link_libraries(cleaningSystem_test
  PRIVATE
    Catch2::Catch2WithMain
    CleaningSystemLib
)

