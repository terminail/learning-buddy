cmake_minimum_required(VERSION 3.10)
project(list_basics)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(list_basics_exercises 
    src/list_basics_exercises.cpp)

# Add executable for solution
add_executable(list_basics_solutions 
    src/list_basics_solutions.cpp)

# Add test executables
add_executable(test_list_basics_basics 
    test/test_list_basics_basics.cpp)
target_link_libraries(test_list_basics_basics GTest::GTest GTest::Main)

add_executable(test_list_basics_practice 
    test/test_list_basics_practice.cpp)
target_link_libraries(test_list_basics_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(list_basics_exercises PRIVATE /W4)
    target_compile_options(list_basics_solutions PRIVATE /W4)
    target_compile_options(test_list_basics_basics PRIVATE /W4)
    target_compile_options(test_list_basics_practice PRIVATE /W4)
else()
    target_compile_options(list_basics_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(list_basics_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_list_basics_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_list_basics_practice PRIVATE -Wall -Wextra -pedantic)
endif()