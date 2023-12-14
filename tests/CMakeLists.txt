find_package(Catch2 3 REQUIRED)

IF (${Catch2_FOUND})
    MESSAGE(STATUS "Found Catch2")
ELSE (${Catch2_FOUND})
    MESSAGE(STATUS "Cound not find Catch2. Check to make sure its installed on your system!")
ENDIF (${Catch2_FOUND})

add_executable(cleanAccessory_test cleanAccessory_test.cpp)
add_executable(clean_test clean_test.cpp)
add_executable(maintenance_test maintenance_test.cpp)

target_compile_features(cleanAccessory_test PRIVATE cxx_std_20)
target_compile_features(clean_test PRIVATE cxx_std_20)
target_compile_features(maintenance_test PRIVATE cxx_std_20)

target_link_libraries(cleanAccessory_test
  PRIVATE
    Catch2::Catch2WithMain
    CleaningSystemLib
)

target_link_libraries(clean_test
  PRIVATE
    Catch2::Catch2WithMain
    CleaningSystemLib
)

target_link_libraries(maintenance_test
  PRIVATE
    Catch2::Catch2WithMain
    CleaningSystemLib
)

