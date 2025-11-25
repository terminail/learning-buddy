# Chapter 12: Dynamic Memory Exercises Overview

This directory contains exercises for Chapter 12 of C++ Primer 5th Edition, which covers dynamic memory management in C++.

## Exercise Progression

### 12.1a: Dynamic Memory Allocation
**Directory**: [dynamic_allocation](dynamic_allocation/)
**Focus**: Basic dynamic memory allocation with new and delete
- Allocating memory for single objects
- Allocating memory for arrays
- Proper deallocation with delete and delete[]
- Memory leak prevention
- Best practices for manual memory management

### 12.1b: Smart Pointers
**Directory**: [smart_pointers](smart_pointers/)
**Focus**: Automatic memory management with smart pointers
- Using std::unique_ptr for exclusive ownership
- Using std::shared_ptr for shared ownership
- Using std::weak_ptr to break circular references
- Automatic deallocation and exception safety
- Performance considerations

## Learning Path

Students should complete these exercises in order:
1. **Dynamic Memory Allocation** - Start with fundamental dynamic memory concepts
2. **Smart Pointers** - Learn about automatic memory management

## Key Concepts Covered

### Dynamic Memory Allocation
- **new operator**: Allocating memory for single objects and arrays
- **delete operator**: Deallocating memory for single objects
- **delete[] operator**: Deallocating memory for arrays
- **Memory leaks**: Understanding and preventing memory leaks
- **Dangling pointers**: Understanding and avoiding dangling pointers

### Smart Pointers
- **std::unique_ptr**: Exclusive ownership with automatic cleanup
- **std::shared_ptr**: Shared ownership with reference counting
- **std::weak_ptr**: Non-owning reference to break cycles
- **make_unique and make_shared**: Factory functions for smart pointer creation
- **Custom deleters**: Providing custom cleanup functions

## Prerequisites

Students should be familiar with:
- Basic C++ syntax and data types
- Pointers and references
- Arrays and basic data structures
- Object-oriented programming concepts