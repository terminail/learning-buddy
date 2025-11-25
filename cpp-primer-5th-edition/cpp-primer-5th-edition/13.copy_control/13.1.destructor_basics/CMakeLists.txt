cmake_minimum_required(VERSION 3.10)
project(destructor_basics)

set(CMAKE_CXX_STANDARD 17)

# Create executable for exercises
add_executable(destructor_basics_exercises 
    src/destructor_basics_exercises.cpp
)

# Create executable for solutions
add_executable(destructor_basics_solutions 
    src/destructor_basics_solutions.cpp
)

# Create executables for tests
add_executable(test_destructor_basics_basics
    test/test_destructor_basics_basics.cpp
)

add_executable(test_destructor_basics_practice
    test/test_destructor_basics_practice.cpp
)

# Link Google Test library to test executables
find_package(GTest REQUIRED)
target_link_libraries(test_destructor_basics_basics GTest::gtest_main)
target_link_libraries(test_destructor_basics_practice GTest::gtest_main)

# Link pthread library if needed
# target_link_libraries(destructor_basics_exercises pthread)
# target_link_libraries(destructor_basics_solutions pthread)