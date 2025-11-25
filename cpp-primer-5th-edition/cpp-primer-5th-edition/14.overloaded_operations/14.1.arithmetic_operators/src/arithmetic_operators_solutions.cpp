#include <iostream>
#include <string>

// Solution: Implement a class with overloaded arithmetic operators
class Complex {
private:
    double real;
    double imag;

public:
    // Solution: Implement constructors
    Complex() : real(0.0), imag(0.0) {}
    
    Complex(double r, double i) : real(r), imag(i) {}
    
    // Solution: Implement overloaded arithmetic operators as member functions
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }
    
    Complex& operator-=(const Complex& other) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }
    
    Complex& operator*=(const Complex& other) {
        double new_real = real * other.real - imag * other.imag;
        double new_imag = real * other.imag + imag * other.real;
        real = new_real;
        imag = new_imag;
        return *this;
    }
    
    Complex& operator/=(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        double new_real = (real * other.real + imag * other.imag) / denominator;
        double new_imag = (imag * other.real - real * other.imag) / denominator;
        real = new_real;
        imag = new_imag;
        return *this;
    }
    
    // Solution: Implement getters for real and imaginary parts
    double getReal() const { return real; }
    double getImag() const { return imag; }
    
    // Solution: Implement a display method to print the complex number
    void display() const {
        if (imag >= 0) {
            std::cout << real << " + " << imag << "i" << std::endl;
        } else {
            std::cout << real << " - " << -imag << "i" << std::endl;
        }
    }
};

// Solution: Implement non-member operator functions
Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex result = lhs;  // Use copy constructor
    result += rhs;         // Use compound assignment
    return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    Complex result = lhs;
    result -= rhs;
    return result;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    Complex result = lhs;
    result *= rhs;
    return result;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    Complex result = lhs;
    result /= rhs;
    return result;
}

int main() {
    // Solution: Create Complex objects and demonstrate operator overloading
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    
    std::cout << "c1: ";
    c1.display();
    
    std::cout << "c2: ";
    c2.display();
    
    std::cout << "c1 + c2: ";
    (c1 + c2).display();
    
    std::cout << "c1 - c2: ";
    (c1 - c2).display();
    
    std::cout << "c1 * c2: ";
    (c1 * c2).display();
    
    std::cout << "c1 / c2: ";
    (c1 / c2).display();
    
    return 0;
}