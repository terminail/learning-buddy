// Solution to Exercise 6.1.1: Functions

#include <iostream>
#include <string>

// Function prototypes
int multiply(int a, int b);
void greet_user(const std::string& name);
double calculate_circle_area(double radius);
bool is_even(int number);

int main() {
    // Test multiply function
    int result = multiply(4, 5);
    std::cout << "4 * 5 = " << result << std::endl;
    
    // Test greet_user function
    greet_user("Alice");
    
    // Test calculate_circle_area function
    double area = calculate_circle_area(3.0);
    std::cout << "Area of circle with radius 3: " << area << std::endl;
    
    // Test is_even function
    int num = 8;
    if (is_even(num)) {
        std::cout << num << " is even" << std::endl;
    } else {
        std::cout << num << " is odd" << std::endl;
    }
    
    // Get user input and test functions
    std::string user_name;
    std::cout << "\nEnter your name: ";
    std::getline(std::cin, user_name);
    greet_user(user_name);
    
    int number1, number2;
    std::cout << "Enter two numbers to multiply: ";
    std::cin >> number1 >> number2;
    std::cout << number1 << " * " << number2 << " = " << multiply(number1, number2) << std::endl;
    
    return 0;
}

// Function definitions
int multiply(int a, int b) {
    return a * b;
}

void greet_user(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

double calculate_circle_area(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}

bool is_even(int number) {
    return (number % 2 == 0);
}