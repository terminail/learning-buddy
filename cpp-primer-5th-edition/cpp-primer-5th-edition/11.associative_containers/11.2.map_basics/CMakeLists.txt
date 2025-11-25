cmake_minimum_required(VERSION 3.10)
project(map_basics)

set(CMAKE_CXX_STANDARD 17)

# Find GTest
find_package(GTest REQUIRED)

# Create executable for exercises
add_executable(map_basics_exercises 
    src/map_basics_exercises.cpp
)

# Create executable for solutions
add_executable(map_basics_solutions 
    src/map_basics_solutions.cpp
)

# Create executable for basic tests
add_executable(test_map_basics_basics
    test/test_map_basics_basics.cpp
)
target_link_libraries(test_map_basics_basics GTest::GTest GTest::Main)

# Create executable for practice tests
add_executable(test_map_basics_practice
    test/test_map_basics_practice.cpp
)
target_link_libraries(test_map_basics_practice GTest::GTest GTest::Main)

# Link pthread library if needed
# target_link_libraries(map_basics_exercises pthread)
# target_link_libraries(map_basics_solutions pthread)