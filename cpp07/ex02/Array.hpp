#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // For std::exception
#include <cstddef>   // For size_t / unsigned int compatibility for size

template <typename T>
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    // Constructors
    Array();
    Array(unsigned int n);
    Array(const Array& other);

    // Destructor
    ~Array();

    // Operators
    Array& operator=(const Array& other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const; // Add const version for const objects

    // Member functions
    unsigned int size() const;

    // Custom exception class (optional, but good practice)
    class IndexOutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Index is out of bounds";
        }
    };
};

#include "Array.tpp" // Include tpp for template implementations

#endif // ARRAY_HPP
