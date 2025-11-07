#ifndef EXERCISE_NAME_EXERCISES_H
#define EXERCISE_NAME_EXERCISES_H

#include <string>
#include <vector>
#include <memory>

namespace cpp_primer {

/**
 * @class ExerciseName
 * @brief Student implementation template for C++ Primer exercises
 * 
 * This class provides a structured approach to learning C++ concepts
 * through hands-on implementation. Students should complete the TODO
 * comments following the exercise guide.
 * 
 * Learning Approach:
 * 1. Read function declarations and understand requirements
 * 2. Implement functions in src/exercise_name_exercises.cpp
 * 3. Run tests to validate implementations
 * 4. Compare with solutions in exercise_name_solutions.h
 * 
 * Customization Instructions:
 * 1. Update class name: ExerciseName → YourExerciseName
 * 2. Update function declarations for your specific exercise
 * 3. Add/remove member variables as needed
 * 4. Update namespace if desired
 */
class ExerciseName {
public:
    // ========== CONSTRUCTORS AND DESTRUCTORS ==========
    
    /**
     * @brief Default constructor
     * Initializes with default value
     * TODO: Implement default constructor
     */
    ExerciseName();
    
    /**
     * @brief Parameterized constructor
     * @param initial_value Initial value for the exercise
     * TODO: Implement with input validation
     */
    explicit ExerciseName(const std::string& initial_value);
    
    /**
     * @brief Copy constructor
     * @param other Object to copy from
     * TODO: Implement deep copy if needed
     */
    ExerciseName(const ExerciseName& other);
    
    /**
     * @brief Destructor
     * TODO: Implement cleanup if needed
     */
    ~ExerciseName();
    
    // ========== GENERIC METHODS ==========
    
    /**
     * @brief Generic method for basic operations
     * @param input Input parameter
     * @return Processed result
     * TODO: Implement your basic functionality
     */
    return_type method_abc(parameter_type input);
    
    /**
     * @brief Generic method for intermediate operations
     * @param param1 First parameter
     * @param param2 Second parameter
     * @return Combined result
     * TODO: Implement your intermediate functionality
     */
    return_type method_def(parameter_type param1, parameter_type param2);
    
    /**
     * @brief Generic method for advanced operations
     * @param param Input parameter
     * @return Processed result
     * TODO: Implement your advanced functionality
     */
    return_type method_ghi(parameter_type param);
    
    // ========== GETTERS AND SETTERS ==========
    
    /**
     * @brief Get current value
     * @return Current value
     */
    return_type get_value() const;
    
    /**
     * @brief Set current value
     * @param value New value to set
     * TODO: Implement with validation
     */
    void set_value(parameter_type value);
    
    /**
     * @brief Get data size/length
     * @return Length of current value
     */
    size_t get_length() const;
    
private:
    // TODO: Add your member variables as needed
    // Example: std::string value_;
    
    // Add any additional private members as needed
};

} // namespace cpp_primer

#endif // EXERCISE_NAME_EXERCISES_H