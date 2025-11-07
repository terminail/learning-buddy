cmake_minimum_required(VERSION 3.10)
project(pair_multimap_basics)

set(CMAKE_CXX_STANDARD 17)

# Create executable for exercises
add_executable(pair_multimap_basics_exercises 
    src/pair_multimap_basics_exercises.cpp
)

# Create executable for solutions
add_executable(pair_multimap_basics_solutions 
    src/pair_multimap_basics_solutions.cpp
)

# Link pthread library if needed
# target_link_libraries(pair_multimap_basics_exercises pthread)
# target_link_libraries(pair_multimap_basics_solutions pthread)