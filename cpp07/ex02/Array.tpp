// Template implementations for Array.hpp
#ifndef ARRAY_TPP // Optional guard, Array.hpp includes it directly
#define ARRAY_TPP // Not strictly needed if Array.hpp is guarded and includes it once

// Default Constructor
template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {
    // Implementation in .tpp
}

// Constructor with size
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {
    // new T[n]() will value-initialize elements (e.g., 0 for int)
    // If default construction is fine (no value-initialization needed for T),
    // then new T[n] is also okay. Subject says "initialized by default".
    // "Try to compile int * a = new int(); then display *a." suggests value-initialization.
}

// Copy Constructor
template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0) {
    // Implementation in .tpp
    *this = other; // Use assignment operator for deep copy logic
}

// Destructor
template <typename T>
Array<T>::~Array() {
    // Implementation in .tpp
    delete[] _array;
}

// Assignment Operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    // Implementation in .tpp
    if (this != &other) {
        delete[] _array; // Free existing memory
        _size = other._size;
        _array = new T[_size]; // Allocate new memory
        for (unsigned int i = 0; i < _size; ++i) {
            _array[i] = other._array[i]; // Copy elements
        }
    }
    return *this;
}

// Subscript Operator (non-const)
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    // Implementation in .tpp
    if (index >= _size) {
        throw IndexOutOfBoundsException();
    }
    return _array[index];
}

// Subscript Operator (const)
// Added for completeness and to support const Array objects
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw IndexOutOfBoundsException();
    }
    return _array[index];
}

// Size Method
template <typename T>
unsigned int Array<T>::size() const {
    // Implementation in .tpp
    return _size;
}

#endif // ARRAY_TPP
