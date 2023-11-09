add_executable(ProgramMain
  ProgramMain.cpp
)

target_link_libraries(ProgramMain
  PRIVATE
    CleaningSystemLib
)

target_compile_features(ProgramMain PRIVATE cxx_std_20)
