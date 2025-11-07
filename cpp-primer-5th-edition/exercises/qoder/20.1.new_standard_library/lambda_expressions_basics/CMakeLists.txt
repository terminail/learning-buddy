cmake_minimum_required(VERSION 3.10)
project(lambda_expressions_basics)

set(CMAKE_CXX_STANDARD 17)

# Create executable for exercises
add_executable(lambda_expressions_basics_exercises 
    src/lambda_expressions_basics_exercises.cpp
)

# Create executable for solutions
add_executable(lambda_expressions_basics_solutions 
    src/lambda_expressions_basics_solutions.cpp
)

# Create test executable for basic tests
add_executable(test_lambda_expressions_basics_basics
    test/test_lambda_expressions_basics_basics.cpp
)

# Create test executable for practice tests
add_executable(test_lambda_expressions_basics_practice
    test/test_lambda_expressions_basics_practice.cpp
)

# Link Google Test
find_package(GTest REQUIRED)
target_link_libraries(test_lambda_expressions_basics_basics GTest::GTest GTest::Main)
target_link_libraries(test_lambda_expressions_basics_practice GTest::GTest GTest::Main)

# Enable testing
enable_testing()
add_test(NAME lambda_expressions_basics_basics COMMAND test_lambda_expressions_basics_basics)
add_test(NAME lambda_expressions_basics_practice COMMAND test_lambda_expressions_basics_practice)