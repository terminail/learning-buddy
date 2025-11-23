cmake_minimum_required(VERSION 3.10)
project(smart_pointers)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create the exercises library
add_library(smart_pointers_exercises src/smart_pointers_exercises.cpp)

# Create the solutions library
add_library(smart_pointers_solutions src/smart_pointers_solutions.cpp)

# Create the basic test executable
add_executable(test_smart_pointers_basics test/test_smart_pointers_basics.cpp)

# Create the practice test executable
add_executable(test_smart_pointers_practice test/test_smart_pointers_practice.cpp)

# Link the libraries to the test executables
target_link_libraries(test_smart_pointers_basics smart_pointers_exercises)
target_link_libraries(test_smart_pointers_practice smart_pointers_exercises)

# Find and link Google Test
find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_link_libraries(test_smart_pointers_basics GTest::GTest GTest::Main)
    target_link_libraries(test_smart_pointers_practice GTest::GTest GTest::Main)
else()
    message(FATAL_ERROR "Google Test not found")
endif()

# Custom targets for running tests
add_custom_target(run_tests
    COMMAND test_smart_pointers_basics
    COMMAND test_smart_pointers_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all smart pointers tests"
)

add_custom_target(run_basics
    COMMAND test_smart_pointers_basics
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running basic smart pointers tests"
)

add_custom_target(run_practice
    COMMAND test_smart_pointers_practice
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running practice smart pointers tests"
)