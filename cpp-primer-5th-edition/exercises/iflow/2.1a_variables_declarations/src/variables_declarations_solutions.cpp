#include "variables_declarations_solutions.h"

namespace cpp_primer {

// ========== CONSTRUCTORS ==========

VariablesDeclarationsSolutions::VariablesDeclarationsSolutions() {
    // Default constructor implementation
}

// ========== VARIABLE DECLARATION METHODS ==========

int VariablesDeclarationsSolutions::declare_integer() {
    // Declare an integer variable and return its value
    int my_int = 42;
    return my_int;
}

double VariablesDeclarationsSolutions::declare_double() {
    // Declare a double variable and return its value
    double my_double = 3.14159;
    return my_double;
}

char VariablesDeclarationsSolutions::declare_character() {
    // Declare a character variable and return its value
    char my_char = 'C';
    return my_char;
}

bool VariablesDeclarationsSolutions::declare_boolean() {
    // Declare a boolean variable and return its value
    bool my_bool = true;
    return my_bool;
}

int VariablesDeclarationsSolutions::use_auto_keyword(int value) {
    // Use the auto keyword to declare a variable
    auto my_auto = value;
    return my_auto;
}

int VariablesDeclarationsSolutions::declare_multiple_variables() {
    // Declare three integer variables and return their sum
    int a = 10, b = 20, c = 30;
    return a + b + c;
}

} // namespace cpp_primer