#ifndef DYNAMIC_ARRAYS_SOLUTIONS_H
#define DYNAMIC_ARRAYS_SOLUTIONS_H

#include <cstddef>
#include <string>

// Forward declaration of SimpleClass
class SimpleClass;

class DynamicArraysSolutions {
public:
    // Exercise 1: Allocate and initialize an array of integers with a given size
    static int* createIntArray(size_t size);

    // Exercise 2: Allocate and initialize an array of SimpleClass objects with a given size
    static SimpleClass* createSimpleClassArray(size_t size);

    // Exercise 3: Deallocate an array of integers
    static void deleteIntArray(int* array);

    // Exercise 4: Deallocate an array of SimpleClass objects
    static void deleteSimpleClassArray(SimpleClass* array);

    // Exercise 5: Copy an array of integers from source to destination
    static void copyIntArray(const int* source, int* destination, size_t size);

    // Exercise 6: Copy an array of SimpleClass objects from source to destination
    static void copySimpleClassArray(const SimpleClass* source, SimpleClass* destination, size_t size);

    // Exercise 7: Resize an array of integers (allocate new array, copy elements, deallocate old)
    static int* resizeIntArray(int* oldArray, size_t oldSize, size_t newSize);

    // Exercise 8: Find an element in an array of integers
    static int* findInIntArray(const int* array, size_t size, int value);

    // Exercise 9: Fill an array of integers with a specific value
    static void fillIntArray(int* array, size_t size, int value);

    // Exercise 10: Calculate the sum of elements in an array of integers
    static int sumIntArray(const int* array, size_t size);

    // Exercise 11: Create a copy of an array of integers
    static int* createCopyOfIntArray(const int* source, size_t size);

    // Exercise 12: Create a copy of an array of SimpleClass objects
    static SimpleClass* createCopyOfSimpleClassArray(const SimpleClass* source, size_t size);
};

#endif // DYNAMIC_ARRAYS_SOLUTIONS_H