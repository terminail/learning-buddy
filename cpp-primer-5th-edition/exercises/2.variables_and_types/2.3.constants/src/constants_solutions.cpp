// Exercise 2.1c: Constants - Solution
// This exercise demonstrates constants and constexpr in C++.

#include <iostream>
#include <array>

// Solution: Use const variables
const int ARRAY_SIZE = 10;
const double PI = 3.14159265359;
const std::string MESSAGE = "Hello, World!";

// Solution: Use constexpr variables
constexpr int COMPILE_TIME_SIZE = 5;
constexpr double E = 2.71828182846;
constexpr int square(int x) { return x * x; }  // constexpr function

int main() {
    // Solution: Use const variables
    std::cout << "Const variables:" << std::endl;
    std::cout << "Array size: " << ARRAY_SIZE << std::endl;
    std::cout << "PI: " << PI << std::endl;
    std::cout << "Message: " << MESSAGE << std::endl;
    
    // Const variables cannot be modified
    // ARRAY_SIZE = 20;  // This would cause a compilation error!
    
    // Solution: Use constexpr variables
    std::cout << "\nConstexpr variables:" << std::endl;
    std::cout << "Compile-time size: " << COMPILE_TIME_SIZE << std::endl;
    std::cout << "E: " << E << std::endl;
    
    // Constexpr can be used in compile-time contexts
    constexpr int SQUARED = square(5);
    std::cout << "5 squared (compile-time): " << SQUARED << std::endl;
    
    // Solution: Work with literal constants
    std::cout << "\nLiteral constants:" << std::endl;
    std::cout << "Integer literal: " << 42 << std::endl;
    std::cout << "Floating-point literal: " << 3.14 << std::endl;
    std::cout << "Scientific notation: " << 1.23e-4 << std::endl;
    std::cout << "Character literal: " << 'A' << std::endl;
    std::cout << "String literal: " << "C++ Programming" << std::endl;
    
    // With suffixes
    std::cout << "Float literal: " << 3.14f << std::endl;
    std::cout << "Long literal: " << 1000000L << std::endl;
    std::cout << "Long long literal: " << 10000000000LL << std::endl;
    
    // Solution: Understand const vs constexpr
    int runtimeValue = 10;
    const int constRuntime = runtimeValue;  // const, but value determined at runtime
    // constexpr int constexprRuntime = runtimeValue;  // Error! Not a compile-time constant
    
    constexpr int compileTimeValue = 20;
    const int constCompileTime = compileTimeValue;  // const, but could also be constexpr
    constexpr int constexprCompileTime = compileTimeValue;  // constexpr
    
    std::cout << "\nConst vs Constexpr:" << std::endl;
    std::cout << "const (runtime): " << constRuntime << std::endl;
    std::cout << "const (compile-time): " << constCompileTime << std::endl;
    std::cout << "constexpr: " << constexprCompileTime << std::endl;
    
    // Solution: Use constexpr in array sizes (must be compile-time constants)
    std::array<int, COMPILE_TIME_SIZE> compileTimeArray{};  // OK
    // std::array<int, runtimeValue> runtimeArray{};  // Error! Not a compile-time constant
    
    std::cout << "Compile-time array size: " << compileTimeArray.size() << std::endl;
    
    return 0;
}