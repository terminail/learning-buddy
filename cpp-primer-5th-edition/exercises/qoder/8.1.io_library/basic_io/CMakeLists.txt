cmake_minimum_required(VERSION 3.10)
project(basic_io)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(basic_io_exercises 
    src/basic_io_exercises.cpp)

# Add executable for solution
add_executable(basic_io_solutions 
    src/basic_io_solutions.cpp)

# Add test executables
add_executable(test_basic_io_basics 
    test/test_basic_io_basics.cpp)
target_link_libraries(test_basic_io_basics GTest::GTest GTest::Main)

add_executable(test_basic_io_practice 
    test/test_basic_io_practice.cpp)
target_link_libraries(test_basic_io_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(basic_io_exercises PRIVATE /W4)
    target_compile_options(basic_io_solutions PRIVATE /W4)
    target_compile_options(test_basic_io_basics PRIVATE /W4)
    target_compile_options(test_basic_io_practice PRIVATE /W4)
else()
    target_compile_options(basic_io_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(basic_io_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_basic_io_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_basic_io_practice PRIVATE -Wall -Wextra -pedantic)
endif()