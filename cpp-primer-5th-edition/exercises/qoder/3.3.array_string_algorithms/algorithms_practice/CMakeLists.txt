cmake_minimum_required(VERSION 3.10)
project(algorithms_practice)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Google Test
find_package(GTest REQUIRED)

# Include directories
include_directories(include)

# Add executable for student exercise
add_executable(algorithms_practice_exercises 
    src/algorithms_practice_exercises.cpp)

# Add executable for solution
add_executable(algorithms_practice_solutions 
    src/algorithms_practice_solutions.cpp)

# Add test executables
add_executable(test_algorithms_practice_basics 
    test/test_algorithms_practice_basics.cpp)
target_link_libraries(test_algorithms_practice_basics GTest::GTest GTest::Main)

add_executable(test_algorithms_practice_practice 
    test/test_algorithms_practice_practice.cpp)
target_link_libraries(test_algorithms_practice_practice GTest::GTest GTest::Main)

# Compiler-specific options
if(MSVC)
    target_compile_options(algorithms_practice_exercises PRIVATE /W4)
    target_compile_options(algorithms_practice_solutions PRIVATE /W4)
    target_compile_options(test_algorithms_practice_basics PRIVATE /W4)
    target_compile_options(test_algorithms_practice_practice PRIVATE /W4)
else()
    target_compile_options(algorithms_practice_exercises PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(algorithms_practice_solutions PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_algorithms_practice_basics PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(test_algorithms_practice_practice PRIVATE -Wall -Wextra -pedantic)
endif()