// Exercise 18.1a: Namespaces - Solution
// This exercise demonstrates namespaces in C++.

#include <iostream>
#include <string>

// Create nested namespaces
namespace Company {
    namespace Graphics {
        void draw() {
            std::cout << "Drawing graphics" << std::endl;
        }
        
        class Shape {
        public:
            virtual void display() const {
                std::cout << "Displaying a shape" << std::endl;
            }
            virtual ~Shape() = default;
        };
    }
    
    namespace Audio {
        void play() {
            std::cout << "Playing audio" << std::endl;
        }
        
        class Sound {
        public:
            void play() const {
                std::cout << "Playing a sound" << std::endl;
            }
        };
    }
}

// Use namespace aliases
namespace CG = Company::Graphics;
namespace CA = Company::Audio;

// Demonstrate namespace scope resolution
void process() {
    std::cout << "Processing in global scope" << std::endl;
}

namespace Utils {
    void process() {
        std::cout << "Processing in Utils namespace" << std::endl;
    }
}

int main() {
    // Use nested namespaces
    Company::Graphics::draw();
    Company::Audio::play();
    
    // Use namespace aliases
    CG::Shape shape;
    shape.display();
    
    CA::Sound sound;
    sound.play();
    
    // Demonstrate namespace scope resolution
    process(); // Calls global process
    Utils::process(); // Calls Utils::process
    
    // Using declarations
    using Utils::process;
    process(); // Calls Utils::process due to using declaration
    
    // Using directives
    {
        using namespace std;
        string message = "Hello from using directive";
        cout << message << endl;
    }
    
    return 0;
}