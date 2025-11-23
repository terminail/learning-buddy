cmake_minimum_required(VERSION 3.10)
project(loop_statements)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(loop_statements_exercises 
    src/loop_statements_exercises.cpp)

# Add executable for solution
add_executable(loop_statements_solutions 
    src/loop_statements_solutions.cpp)

# Add test executables
add_executable(test_loop_statements_basics 
    test/test_loop_statements_basics.cpp)
target_link_libraries(test_loop_statements_basics GTest::GTest GTest::Main)

add_executable(test_loop_statements_practice 
    test/test_loop_statements_practice.cpp)
target_link_libraries(test_loop_statements_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(loop_statements_exercises PRIVATE /W4)
    target_compile_options(loop_statements_solutions PRIVATE /W4)
    target_compile_options(test_loop_statements_basics PRIVATE /W4)
    target_compile_options(test_loop_statements_practice PRIVATE /W4)
else()
    target_compile_options(loop_statements_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(loop_statements_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_loop_statements_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_loop_statements_practice PRIVATE -Wall -Wextra -pedantic)
endif()