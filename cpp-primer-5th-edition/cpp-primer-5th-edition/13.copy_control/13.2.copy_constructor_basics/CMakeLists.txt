cmake_minimum_required(VERSION 3.10)
project(copy_constructor_basics)

set(CMAKE_CXX_STANDARD 17)

# Create executable for exercises
add_executable(copy_constructor_basics_exercises 
    src/copy_constructor_basics_exercises.cpp
)

# Create executable for solutions
add_executable(copy_constructor_basics_solutions 
    src/copy_constructor_basics_solutions.cpp
)

# Create executables for tests
add_executable(test_copy_constructor_basics_basics
    test/test_copy_constructor_basics_basics.cpp
)

add_executable(test_copy_constructor_basics_practice
    test/test_copy_constructor_basics_practice.cpp
)

# Link Google Test library to test executables
find_package(GTest REQUIRED)
target_link_libraries(test_copy_constructor_basics_basics GTest::gtest_main)
target_link_libraries(test_copy_constructor_basics_practice GTest::gtest_main)

# Link pthread library if needed
# target_link_libraries(copy_constructor_basics_exercises pthread)
# target_link_libraries(copy_constructor_basics_solutions pthread)