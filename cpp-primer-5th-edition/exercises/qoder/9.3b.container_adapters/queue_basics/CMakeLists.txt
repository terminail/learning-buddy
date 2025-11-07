cmake_minimum_required(VERSION 3.10)
project(queue_basics)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(queue_basics_exercises 
    src/queue_basics_exercises.cpp)

# Add executable for solution
add_executable(queue_basics_solutions 
    src/queue_basics_solutions.cpp)

# Add test executables
add_executable(test_queue_basics_basics 
    test/test_queue_basics_basics.cpp)
target_link_libraries(test_queue_basics_basics GTest::GTest GTest::Main)

add_executable(test_queue_basics_practice 
    test/test_queue_basics_practice.cpp)
target_link_libraries(test_queue_basics_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(queue_basics_exercises PRIVATE /W4)
    target_compile_options(queue_basics_solutions PRIVATE /W4)
    target_compile_options(test_queue_basics_basics PRIVATE /W4)
    target_compile_options(test_queue_basics_practice PRIVATE /W4)
else()
    target_compile_options(queue_basics_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(queue_basics_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_queue_basics_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_queue_basics_practice PRIVATE -Wall -Wextra -pedantic)
endif()