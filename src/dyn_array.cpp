#include "dyn_array.h"

/**
 * @file dyn_array.cpp
 * @brief This file contains the implementations of the DynamicArray and DynamicArrayVector classes.
 */

namespace oop_practice3 {


   // Default Constructor
    DynamicArray::DynamicArray() : size(10), head(new int[size]) /*elements(std::vector<int>(10))*/ {}

    // Deep copy constructor for pointer array
    DynamicArray::DynamicArray(int in_size, int* in_head)
        : size(in_size), head(new int[in_size]) /*elements(in_size)*/ {
        for (int i = 0; i < size; ++i) {
            head[i] = in_head[i];
            /*elements[i] = in_head[i];*/
        }
    }


    DynamicArray::DynamicArray(int in_size)
        : size(in_size), /*elements(in_size)*/ head(new int[size]{}) {  
    }

    DynamicArray::DynamicArray(int in_size, int in_val)
        : size(in_size), /*elements(in_size)*/ head(new int[size]) {
        for (int i = 0; i < in_size; i++) {
            head[i] = in_val;      // Set each element to in_val
            // elements[i] = in_val;  // Set elements vector to in_val
        }
    }

    // Copy Constructor
    DynamicArray::DynamicArray(const DynamicArray& other) 
        : size(other.size), head(nullptr) /*elements(other.elements)*/ {
        if (other.head) {
            head = new int[other.size];
            for (int i = 0; i < other.size; i++) {
                head[i] = other.head[i];
            }
        }
    }
    

    // Move Constructor
    DynamicArray::DynamicArray(DynamicArray&& other) noexcept 
        : size(other.size), head(other.head) /*elements(std::move(other.elements))*/ {
        other.head = nullptr;
        other.size = 0;
    }

    // Getters

    int DynamicArray::getSize() const {
        return this->size;
    }

    int* DynamicArray::getHead() const {
        return this->head;
    }

    // std::vector<int>& DynamicArray::getElements() {
    // return this->elements;  // Return a reference to the internal vector
    // }

    // const std::vector<int>& DynamicArray::getElements() const {
    //     return this->elements;  // Return a const reference for read-only access
    // }
        // Destructor
    DynamicArray::~DynamicArray() {
        if (head != nullptr) {
            delete[] head;
        }
    }

    // Move Assignment Operator
    DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept {
    if (this != &other) {
        delete[] head;  // Free current object's memory
        head = other.head;
        size = other.size;
        other.head = nullptr;  // Avoid double deletion
        other.size = 0;
    }
    return *this;
    }

    // Remember: the return type int& returns a reference to an int

    int& DynamicArray::operator[](int index) {
        if (index >= 0 && index < size) {
            return this->head[index]; 
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    const int& DynamicArray::operator[](int index) const {
        if (index >= 0 && index < size) {
            return this->head[index];  
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    DynamicArray operator+(const DynamicArray& lhs, const DynamicArray& rhs) {
        // Create a new DynamicArray with combined size
        DynamicArray result(lhs.getSize() + rhs.getSize());

        // Copy elements from lhs to result
        for (int i = 0; i < lhs.getSize(); i++) {
            result[i] = lhs[i];
        }

        // Append elements from rhs to result
        for (int i = 0; i < rhs.getSize(); i++) {
            result[i + lhs.getSize()] = rhs[i];
        }

        return result;
    }


    // Set an element in the array
    void DynamicArray::setElementAt(int index, int value) {
        if (index >= 0 && index < size) {
            // elements[index] = value;  // Update vector
            head[index] = value;      // Synchronize with head array
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Get an element from the array
    int DynamicArray::getElementAt(int index) const {
        if (index >= 0 && index < size) {
            return this->head[index];
        }
        throw std::out_of_range("Index out of range");
    }


    // Default Constructor
    DynamicArrayVector::DynamicArrayVector() : elements(10) {}

    DynamicArrayVector::DynamicArrayVector(int in_size)
        : elements(in_size) {}

    DynamicArrayVector::DynamicArrayVector(int in_size, int in_val)
        : elements(in_size, in_val) {}

    // Copy Constructor
    DynamicArrayVector::DynamicArrayVector(const DynamicArrayVector& other)
        : elements(other.elements) {}

    // Move Constructor
    DynamicArrayVector::DynamicArrayVector(DynamicArrayVector&& other) noexcept
        : elements(std::move(other.elements)) {}

    // Move Assignment Operator
    DynamicArrayVector& DynamicArrayVector::operator=(DynamicArrayVector&& other) noexcept {
        if (this != &other) {
            elements = std::move(other.elements);
        }
        return *this;
    }

    // Operator [] Overloads
    int& DynamicArrayVector::operator[](int index) {
        if (index >= 0 && index < getSize()) {
            return elements[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    const int& DynamicArrayVector::operator[](int index) const {
        if (index >= 0 && index < getSize()) {
            return elements[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Overload the + operator to concatenate two DynamicArrayVector objects
    DynamicArrayVector operator+(const DynamicArrayVector& lhs, const DynamicArrayVector& rhs) {
        DynamicArrayVector result(lhs.getSize() + rhs.getSize());

        // Copy elements from lhs
        for (int i = 0; i < lhs.getSize(); ++i) {
            result[i] = lhs[i];
        }

        // Copy elements from rhs
        for (int i = 0; i < rhs.getSize(); ++i) {
            result[i + lhs.getSize()] = rhs[i];
        }

        return result;
    }

    // Getter for size
    int DynamicArrayVector::getSize() const {
        return elements.size();
    }

    // Getter for elements vector (non-const version)
    std::vector<int>& DynamicArrayVector::getElements() {
        return elements;
    }

    // Getter for elements vector (const version)
    const std::vector<int>& DynamicArrayVector::getElements() const {
        return elements;
    }

    // Set an element in the array
    void DynamicArrayVector::setElementAt(int index, int value) {
        if (index >= 0 && index < getSize()) {
            elements[index] = value;
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    // Get an element from the array
    int DynamicArrayVector::getElementAt(int index) const {
        if (index >= 0 && index < getSize()) {
            return elements[index];
        }
        throw std::out_of_range("Index out of range");
    }
}
