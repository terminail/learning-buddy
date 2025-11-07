#ifndef SEQUENTIAL_CONTAINERS_EXERCISES_H
#define SEQUENTIAL_CONTAINERS_EXERCISES_H

#include <string>
#include <vector>
#include <list>
#include <deque>

namespace cpp_primer {

/**
 * @class SequentialContainers
 * @brief Student implementation for C++ sequential containers exercise
 * 
 * This exercise focuses on sequential containers: vector, list, and deque.
 * 
 * Learning Objectives:
 * - Understand different sequential containers and their characteristics
 * - Practice container operations like insertion, deletion, and iteration
 * - Learn about container iterators and their usage
 * - Understand container adapters like stack and queue
 */
class SequentialContainers {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    SequentialContainers();
    
    // ========== VECTOR OPERATIONS ==========
    
    /**
     * @brief Create and populate a vector with integers
     * @param size Size of the vector
     * @param initial_value Initial value for all elements
     * @return A vector with the given size and initial value
     */
    std::vector<int> create_vector(int size, int initial_value);
    
    /**
     * @brief Add elements to the end of a vector
     * @param vec Reference to the vector
     * @param elements Elements to add
     */
    void add_to_vector(std::vector<int>& vec, const std::vector<int>& elements);
    
    /**
     * @brief Remove elements from a vector that match a value
     * @param vec Reference to the vector
     * @param value Value to remove
     * @return Number of elements removed
     */
    int remove_from_vector(std::vector<int>& vec, int value);
    
    // ========== LIST OPERATIONS ==========
    
    /**
     * @brief Create and populate a list with integers
     * @param size Size of the list
     * @param initial_value Initial value for all elements
     * @return A list with the given size and initial value
     */
    std::list<int> create_list(int size, int initial_value);
    
    /**
     * @brief Insert an element at a specific position in a list
     * @param lst Reference to the list
     * @param position Position to insert at (0-based index)
     * @param value Value to insert
     */
    void insert_in_list(std::list<int>& lst, int position, int value);
    
    /**
     * @brief Sort a list in ascending order
     * @param lst Reference to the list
     */
    void sort_list(std::list<int>& lst);
    
    // ========== DEQUE OPERATIONS ==========
    
    /**
     * @brief Create and populate a deque with integers
     * @param size Size of the deque
     * @param initial_value Initial value for all elements
     * @return A deque with the given size and initial value
     */
    std::deque<int> create_deque(int size, int initial_value);
    
    /**
     * @brief Add elements to both ends of a deque
     * @param deq Reference to the deque
     * @param front_value Value to add to front
     * @param back_value Value to add to back
     */
    void add_to_deque_ends(std::deque<int>& deq, int front_value, int back_value);
    
    /**
     * @brief Remove elements from both ends of a deque
     * @param deq Reference to the deque
     * @return Pair of removed elements (front, back)
     */
    std::pair<int, int> remove_from_deque_ends(std::deque<int>& deq);
    
private:
    // Member variables can be added here if needed
};

} // namespace cpp_primer

#endif // SEQUENTIAL_CONTAINERS_EXERCISES_H