cmake_minimum_required(VERSION 3.10)
project(string_operations)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(string_operations_exercises 
    src/string_operations_exercises.cpp)

# Add executable for solution
add_executable(string_operations_solutions 
    src/string_operations_solutions.cpp)

# Add test executables
add_executable(test_string_operations_basics 
    test/test_string_operations_basics.cpp)
target_link_libraries(test_string_operations_basics GTest::GTest GTest::Main)

add_executable(test_string_operations_practice 
    test/test_string_operations_practice.cpp)
target_link_libraries(test_string_operations_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(string_operations_exercises PRIVATE /W4)
    target_compile_options(string_operations_solutions PRIVATE /W4)
    target_compile_options(test_string_operations_basics PRIVATE /W4)
    target_compile_options(test_string_operations_practice PRIVATE /W4)
else()
    target_compile_options(string_operations_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(string_operations_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_string_operations_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_string_operations_practice PRIVATE -Wall -Wextra -pedantic)
endif()