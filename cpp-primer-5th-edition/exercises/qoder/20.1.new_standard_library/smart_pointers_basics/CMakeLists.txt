cmake_minimum_required(VERSION 3.10)
project(smart_pointers_basics)

set(CMAKE_CXX_STANDARD 17)

# Create executable for exercises
add_executable(smart_pointers_basics_exercises 
    src/smart_pointers_basics_exercises.cpp
)

# Create executable for solutions
add_executable(smart_pointers_basics_solutions 
    src/smart_pointers_basics_solutions.cpp
)

# Create test executable for basic tests
add_executable(test_smart_pointers_basics_basics
    test/test_smart_pointers_basics_basics.cpp
)

# Create test executable for practice tests
add_executable(test_smart_pointers_basics_practice
    test/test_smart_pointers_basics_practice.cpp
)

# Link Google Test
find_package(GTest REQUIRED)
target_link_libraries(test_smart_pointers_basics_basics GTest::GTest GTest::Main)
target_link_libraries(test_smart_pointers_basics_practice GTest::GTest GTest::Main)

# Enable testing
enable_testing()
add_test(NAME smart_pointers_basics_basics COMMAND test_smart_pointers_basics_basics)
add_test(NAME smart_pointers_basics_practice COMMAND test_smart_pointers_basics_practice)