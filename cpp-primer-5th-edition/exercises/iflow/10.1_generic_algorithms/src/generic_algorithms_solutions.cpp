#include "generic_algorithms_solutions.h"
#include <algorithm>
#include <numeric>

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

GenericAlgorithmsSolutions::GenericAlgorithmsSolutions() {
    // Default constructor implementation
}

// ========== FINDING ALGORITHMS ==========

template<typename Container>
typename Container::iterator GenericAlgorithmsSolutions::find_element(Container& container, const typename Container::value_type& value) {
    // Find an element in a container
    return std::find(container.begin(), container.end(), value);
}

template<typename Container>
int GenericAlgorithmsSolutions::count_occurrences(const Container& container, const typename Container::value_type& value) {
    // Count occurrences of a value in a container
    return std::count(container.begin(), container.end(), value);
}

// ========== SORTING ALGORITHMS ==========

template<typename Container>
void GenericAlgorithmsSolutions::sort_container(Container& container) {
    // Sort a container in ascending order
    std::sort(container.begin(), container.end());
}

template<typename Container, typename Comparator>
void GenericAlgorithmsSolutions::sort_container_custom(Container& container, Comparator comp) {
    // Sort a container with a custom comparator
    std::sort(container.begin(), container.end(), comp);
}

// ========== TRANSFORMATION ALGORITHMS ==========

template<typename Container, typename Function>
void GenericAlgorithmsSolutions::transform_container(Container& container, Function func) {
    // Transform elements in a container using a function
    std::transform(container.begin(), container.end(), container.begin(), func);
}

template<typename SourceContainer, typename DestinationContainer, typename Condition>
int GenericAlgorithmsSolutions::copy_if_condition(const SourceContainer& source, DestinationContainer& destination, Condition condition) {
    // Copy elements from one container to another based on a condition
    auto it = std::copy_if(source.begin(), source.end(), std::back_inserter(destination), condition);
    return std::distance(destination.begin(), destination.end());
}

// ========== NUMERIC ALGORITHMS ==========

template<typename Container>
typename Container::value_type GenericAlgorithmsSolutions::sum_container(const Container& container) {
    // Calculate the sum of elements in a container
    return std::accumulate(container.begin(), container.end(), typename Container::value_type{});
}

// ========== SEARCHING ALGORITHMS ==========

template<typename Container, typename Condition>
typename Container::iterator GenericAlgorithmsSolutions::find_if_condition(Container& container, Condition condition) {
    // Find the first element that matches a condition
    return std::find_if(container.begin(), container.end(), condition);
}

// Explicit template instantiation to avoid linker errors
template class GenericAlgorithmsSolutions;

} // namespace cpp_primer