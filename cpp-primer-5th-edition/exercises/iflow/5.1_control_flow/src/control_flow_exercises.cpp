#include "control_flow_exercises.h"

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

ControlFlow::ControlFlow() {
    // Default constructor implementation
}

// ========== CONDITIONAL STATEMENTS ==========

std::string ControlFlow::check_number_sign(int number) {
    // TODO: Implement to check if number is positive, negative, or zero
    // Example:
    // if (number > 0) {
    //     return "positive";
    // } else if (number < 0) {
    //     return "negative";
    // } else {
    //     return "zero";
    // }
    
    // Replace with your implementation
    return "";  // Placeholder
}

int ControlFlow::find_maximum(int a, int b, int c) {
    // TODO: Implement to find maximum of three numbers using if statements
    // Example:
    // if (a >= b && a >= c) {
    //     return a;
    // } else if (b >= a && b >= c) {
    //     return b;
    // } else {
    //     return c;
    // }
    
    // Replace with your implementation
    return 0;  // Placeholder
}

// ========== LOOP STATEMENTS ==========

int ControlFlow::sum_with_for_loop(int n) {
    // TODO: Implement to calculate sum using for loop
    // Example:
    // int sum = 0;
    // for (int i = 1; i <= n; i++) {
    //     sum += i;
    // }
    // return sum;
    
    // Replace with your implementation
    return 0;  // Placeholder
}

int ControlFlow::sum_with_while_loop(int n) {
    // TODO: Implement to calculate sum using while loop
    // Example:
    // int sum = 0;
    // int i = 1;
    // while (i <= n) {
    //     sum += i;
    //     i++;
    // }
    // return sum;
    
    // Replace with your implementation
    return 0;  // Placeholder
}

int ControlFlow::sum_even_numbers(const std::vector<int>& numbers) {
    // TODO: Implement to sum all even numbers in vector
    // Example:
    // int sum = 0;
    // for (int num : numbers) {
    //     if (num % 2 == 0) {
    //         sum += num;
    //     }
    // }
    // return sum;
    
    // Replace with your implementation
    return 0;  // Placeholder
}

// ========== SWITCH STATEMENTS ==========

char ControlFlow::convert_to_letter_grade(int grade) {
    // TODO: Implement to convert numeric grade to letter grade
    // Example:
    // if (grade >= 90) {
    //     return 'A';
    // } else if (grade >= 80) {
    //     return 'B';
    // } else if (grade >= 70) {
    //     return 'C';
    // } else if (grade >= 60) {
    //     return 'D';
    // } else {
    //     return 'F';
    // }
    
    // Replace with your implementation
    return 'F';  // Placeholder
}

// ========== BREAK AND CONTINUE ==========

int ControlFlow::find_first_even(const std::vector<int>& numbers) {
    // TODO: Implement to find first even number in vector
    // Example:
    // for (int num : numbers) {
    //     if (num % 2 == 0) {
    //         return num;
    //     }
    // }
    // return -1;
    
    // Replace with your implementation
    return -1;  // Placeholder
}

} // namespace cpp_primer