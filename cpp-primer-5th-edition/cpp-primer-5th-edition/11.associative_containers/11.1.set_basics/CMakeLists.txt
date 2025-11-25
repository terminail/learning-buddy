cmake_minimum_required(VERSION 3.10)
project(set_basics)

set(CMAKE_CXX_STANDARD 17)

# Create executable for exercises
add_executable(set_basics_exercises 
    src/set_basics_exercises.cpp
)

# Create executable for solutions
add_executable(set_basics_solutions 
    src/set_basics_solutions.cpp
)

# Create executables for tests
add_executable(test_set_basics_basics
    test/test_set_basics_basics.cpp
)

add_executable(test_set_basics_practice
    test/test_set_basics_practice.cpp
)

# Link Google Test library to test executables
target_link_libraries(test_set_basics_basics gtest gtest_main)
target_link_libraries(test_set_basics_practice gtest gtest_main)

# Link pthread library if needed
# target_link_libraries(set_basics_exercises pthread)
# target_link_libraries(set_basics_solutions pthread)