// Solution 4.1a: Conditional Expressions
// This exercise demonstrates conditional expressions and statements in C++.

#include <iostream>
#include <vector>

int main() {
    // Solution: Work with conditional (ternary) operators
    int score = 85;
    std::cout << "Score: " << score << std::endl;
    
    // Use the ternary operator (?:) for simple conditional assignments
    std::string grade = (score >= 90) ? "A" : 
                       (score >= 80) ? "B" : 
                       (score >= 70) ? "C" : 
                       (score >= 60) ? "D" : "F";
    std::cout << "Grade (ternary): " << grade << std::endl;
    
    // Compare ternary operators with if-else statements
    std::string grade_if;
    if (score >= 90) {
        grade_if = "A";
    } else if (score >= 80) {
        grade_if = "B";
    } else if (score >= 70) {
        grade_if = "C";
    } else if (score >= 60) {
        grade_if = "D";
    } else {
        grade_if = "F";
    }
    std::cout << "Grade (if-else): " << grade_if << std::endl;
    
    // Solution: Practice if-else statements with multiple conditions
    int age = 25;
    bool has_license = true;
    bool has_insurance = true;
    std::cout << "Age: " << age << ", Has license: " << (has_license ? "Yes" : "No") 
              << ", Has insurance: " << (has_insurance ? "Yes" : "No") << std::endl;
    
    // Use if-else if-else chains for complex conditions
    if (age >= 18 && has_license && has_insurance) {
        std::cout << "Can drive legally" << std::endl;
    } else if (age >= 18 && has_license) {
        std::cout << "Has license but needs insurance" << std::endl;
    } else if (age >= 18) {
        std::cout << "Adult but needs license and insurance" << std::endl;
    } else {
        std::cout << "Too young to drive" << std::endl;
    }
    
    // Use nested if statements for hierarchical conditions
    if (age >= 18) {
        if (has_license) {
            if (has_insurance) {
                std::cout << "Fully qualified driver" << std::endl;
            } else {
                std::cout << "Needs insurance" << std::endl;
            }
        } else {
            std::cout << "Needs license" << std::endl;
        }
    } else {
        std::cout << "Not eligible to drive" << std::endl;
    }
    
    // Solution: Work with switch statements
    int day = 3;
    std::cout << "Day number: " << day << std::endl;
    
    // Use switch statements for multiple discrete values
    switch (day) {
        case 1:
            std::cout << "Monday" << std::endl;
            break;
        case 2:
            std::cout << "Tuesday" << std::endl;
            break;
        case 3:
            std::cout << "Wednesday" << std::endl;
            break;
        case 4:
            std::cout << "Thursday" << std::endl;
            break;
        case 5:
            std::cout << "Friday" << std::endl;
            break;
        case 6:
            std::cout << "Saturday" << std::endl;
            break;
        case 7:
            std::cout << "Sunday" << std::endl;
            break;
        default:
            std::cout << "Invalid day" << std::endl;
            break;
    }
    
    // Handle fall-through cases
    char choice = 'B';
    std::cout << "Choice: " << choice << std::endl;
    switch (choice) {
        case 'A':
        case 'B':
        case 'C':
            std::cout << "Choice is A, B, or C" << std::endl;
            break;
        case 'D':
        case 'E':
            std::cout << "Choice is D or E" << std::endl;
            break;
        default:
            std::cout << "Choice is not A-E" << std::endl;
            break;
    }
    
    // Solution: Evaluate complex expressions
    int a = 5, b = 3, c = 2;
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    
    // Understand operator precedence and associativity
    int result1 = a + b * c;        // Multiplication has higher precedence
    int result2 = (a + b) * c;      // Parentheses override precedence
    std::cout << "a + b * c = " << result1 << std::endl;
    std::cout << "(a + b) * c = " << result2 << std::endl;
    
    // Evaluate expressions with mixed data types
    double result3 = a / b;         // Integer division
    double result4 = static_cast<double>(a) / b;  // Cast for floating-point division
    std::cout << "a / b (integer) = " << result3 << std::endl;
    std::cout << "a / b (floating) = " << result4 << std::endl;
    
    // Solution: Practice short-circuit evaluation
    bool condition1 = true;
    bool condition2 = false;
    int value = 10;
    std::cout << "condition1: " << (condition1 ? "true" : "false") 
              << ", condition2: " << (condition2 ? "true" : "false") 
              << ", value: " << value << std::endl;
    
    // Understand how && and || operators work with short-circuiting
    if (condition1 && ++value > 5) {
        std::cout << "First condition true, value incremented to: " << value << std::endl;
    }
    
    if (condition2 || ++value > 10) {
        std::cout << "Second condition true, value incremented to: " << value << std::endl;
    }
    
    // Use short-circuiting for safe condition checking
    int* ptr = nullptr;
    // This is safe because the first condition will be false, so the second won't be evaluated
    if (ptr != nullptr && *ptr > 0) {
        std::cout << "Pointer value: " << *ptr << std::endl;
    } else {
        std::cout << "Pointer is null, avoiding dereference" << std::endl;
    }
    
    // Safe array access using short-circuiting
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    int index = 10;
    std::cout << "Vector size: " << numbers.size() << ", Index: " << index << std::endl;
    
    // This is safe because the first condition checks bounds before accessing
    if (index < static_cast<int>(numbers.size()) && numbers[index] > 0) {
        std::cout << "Value at index " << index << ": " << numbers[index] << std::endl;
    } else {
        std::cout << "Index out of bounds or value not positive" << std::endl;
    }
    
    return 0;
}