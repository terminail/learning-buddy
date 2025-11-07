#ifndef GENERIC_ALGORITHMS_EXERCISES_H
#define GENERIC_ALGORITHMS_EXERCISES_H

#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

namespace cpp_primer {

/**
 * @class GenericAlgorithms
 * @brief Student implementation for C++ generic algorithms exercise
 * 
 * This exercise focuses on the Standard Template Library (STL) algorithms.
 * 
 * Learning Objectives:
 * - Understand and use common STL algorithms
 * - Learn about function objects and lambdas
 * - Practice using iterators with algorithms
 * - Understand algorithm complexity and efficiency
 */
class GenericAlgorithms {
public:
    // ========== CONSTRUCTORS ==========
    
    /**
     * @brief Default constructor
     */
    GenericAlgorithms();
    
    // ========== FINDING ALGORITHMS ==========
    
    /**
     * @brief Find an element in a container
     * @param container Container to search in
     * @param value Value to find
     * @return Iterator to the found element or end iterator if not found
     */
    template<typename Container>
    typename Container::iterator find_element(Container& container, const typename Container::value_type& value);
    
    /**
     * @brief Count occurrences of a value in a container
     * @param container Container to count in
     * @param value Value to count
     * @return Number of occurrences of the value
     */
    template<typename Container>
    int count_occurrences(const Container& container, const typename Container::value_type& value);
    
    // ========== SORTING ALGORITHMS ==========
    
    /**
     * @brief Sort a container in ascending order
     * @param container Container to sort
     */
    template<typename Container>
    void sort_container(Container& container);
    
    /**
     * @brief Sort a container with a custom comparator
     * @param container Container to sort
     * @param comp Comparator function
     */
    template<typename Container, typename Comparator>
    void sort_container_custom(Container& container, Comparator comp);
    
    // ========== TRANSFORMATION ALGORITHMS ==========
    
    /**
     * @brief Transform elements in a container using a function
     * @param container Container to transform
     * @param func Function to apply to each element
     */
    template<typename Container, typename Function>
    void transform_container(Container& container, Function func);
    
    /**
     * @brief Copy elements from one container to another based on a condition
     * @param source Source container
     * @param destination Destination container
     * @param condition Condition function
     * @return Number of elements copied
     */
    template<typename SourceContainer, typename DestinationContainer, typename Condition>
    int copy_if_condition(const SourceContainer& source, DestinationContainer& destination, Condition condition);
    
    // ========== NUMERIC ALGORITHMS ==========
    
    /**
     * @brief Calculate the sum of elements in a container
     * @param container Container with elements to sum
     * @return Sum of all elements
     */
    template<typename Container>
    typename Container::value_type sum_container(const Container& container);
    
    // ========== SEARCHING ALGORITHMS ==========
    
    /**
     * @brief Find the first element that matches a condition
     * @param container Container to search in
     * @param condition Condition function
     * @return Iterator to the found element or end iterator if not found
     */
    template<typename Container, typename Condition>
    typename Container::iterator find_if_condition(Container& container, Condition condition);
    
private:
    // Member variables can be added here if needed
};

} // namespace cpp_primer

#endif // GENERIC_ALGORITHMS_EXERCISES_H