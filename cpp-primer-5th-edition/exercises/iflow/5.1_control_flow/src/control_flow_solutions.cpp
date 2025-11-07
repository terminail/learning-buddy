#include "control_flow_solutions.h"

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

ControlFlowSolutions::ControlFlowSolutions() {
    // Default constructor implementation
}

// ========== CONDITIONAL STATEMENTS ==========

std::string ControlFlowSolutions::check_number_sign(int number) {
    // Check if number is positive, negative, or zero
    if (number > 0) {
        return "positive";
    } else if (number < 0) {
        return "negative";
    } else {
        return "zero";
    }
}

int ControlFlowSolutions::find_maximum(int a, int b, int c) {
    // Find maximum of three numbers using if statements
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

// ========== LOOP STATEMENTS ==========

int ControlFlowSolutions::sum_with_for_loop(int n) {
    // Calculate sum using for loop
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int ControlFlowSolutions::sum_with_while_loop(int n) {
    // Calculate sum using while loop
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum += i;
        i++;
    }
    return sum;
}

int ControlFlowSolutions::sum_even_numbers(const std::vector<int>& numbers) {
    // Sum all even numbers in vector
    int sum = 0;
    for (int num : numbers) {
        if (num % 2 == 0) {
            sum += num;
        }
    }
    return sum;
}

// ========== SWITCH STATEMENTS ==========

char ControlFlowSolutions::convert_to_letter_grade(int grade) {
    // Convert numeric grade to letter grade
    if (grade >= 90) {
        return 'A';
    } else if (grade >= 80) {
        return 'B';
    } else if (grade >= 70) {
        return 'C';
    } else if (grade >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// ========== BREAK AND CONTINUE ==========

int ControlFlowSolutions::find_first_even(const std::vector<int>& numbers) {
    // Find first even number in vector
    for (int num : numbers) {
        if (num % 2 == 0) {
            return num;
        }
    }
    return -1;
}

} // namespace cpp_primer