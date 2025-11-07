#include "sequential_containers_solutions.h"
#include <algorithm>

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

SequentialContainersSolutions::SequentialContainersSolutions() {
    // Default constructor implementation
}

// ========== VECTOR OPERATIONS ==========

std::vector<int> SequentialContainersSolutions::create_vector(int size, int initial_value) {
    // Create and populate a vector with the given size and initial value
    return std::vector<int>(size, initial_value);
}

void SequentialContainersSolutions::add_to_vector(std::vector<int>& vec, const std::vector<int>& elements) {
    // Add elements to the end of a vector
    vec.insert(vec.end(), elements.begin(), elements.end());
}

int SequentialContainersSolutions::remove_from_vector(std::vector<int>& vec, int value) {
    // Remove elements from a vector that match a value
    int count = 0;
    vec.erase(std::remove_if(vec.begin(), vec.end(),
        [value, &count](int x) {
            if (x == value) {
                count++;
                return true;
            }
            return false;
        }), vec.end());
    return count;
}

// ========== LIST OPERATIONS ==========

std::list<int> SequentialContainersSolutions::create_list(int size, int initial_value) {
    // Create and populate a list with the given size and initial value
    return std::list<int>(size, initial_value);
}

void SequentialContainersSolutions::insert_in_list(std::list<int>& lst, int position, int value) {
    // Insert an element at a specific position in a list
    auto it = lst.begin();
    std::advance(it, position);
    lst.insert(it, value);
}

void SequentialContainersSolutions::sort_list(std::list<int>& lst) {
    // Sort a list in ascending order
    lst.sort();
}

// ========== DEQUE OPERATIONS ==========

std::deque<int> SequentialContainersSolutions::create_deque(int size, int initial_value) {
    // Create and populate a deque with the given size and initial value
    return std::deque<int>(size, initial_value);
}

void SequentialContainersSolutions::add_to_deque_ends(std::deque<int>& deq, int front_value, int back_value) {
    // Add elements to both ends of a deque
    deq.push_front(front_value);
    deq.push_back(back_value);
}

std::pair<int, int> SequentialContainersSolutions::remove_from_deque_ends(std::deque<int>& deq) {
    // Remove elements from both ends of a deque
    int front = deq.front();
    int back = deq.back();
    deq.pop_front();
    deq.pop_back();
    return std::make_pair(front, back);
}

} // namespace cpp_primer