cmake_minimum_required(VERSION 3.10)
project(arithmetic_operators)

set(CMAKE_CXX_STANDARD 17)

# Create executable for exercises
add_executable(arithmetic_operators_exercises 
    src/arithmetic_operators_exercises.cpp
)

# Create executable for solutions
add_executable(arithmetic_operators_solutions 
    src/arithmetic_operators_solutions.cpp
)

# Create executables for tests
add_executable(test_arithmetic_operators_basics
    test/test_arithmetic_operators_basics.cpp
)

add_executable(test_arithmetic_operators_practice
    test/test_arithmetic_operators_practice.cpp
)

# Link Google Test library to test executables
find_package(GTest REQUIRED)
target_link_libraries(test_arithmetic_operators_basics GTest::gtest_main)
target_link_libraries(test_arithmetic_operators_practice GTest::gtest_main)

# Link pthread library if needed
# target_link_libraries(arithmetic_operators_exercises pthread)
# target_link_libraries(arithmetic_operators_solutions pthread)