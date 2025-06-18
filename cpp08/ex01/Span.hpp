#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept> // For exceptions (std::exception base for custom ones)
#include <algorithm> // For std::min_element, std::max_element, std::sort
#include <numeric>   // For std::distance (used in addRange, though often in <iterator>)
                     // The comment about std::adjacent_difference was likely conceptual.
#include <limits>    // For std::numeric_limits

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

    Span(); // Default constructor private as per Orthodox Canonical Form if not used

public:
    explicit Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);

    // Template member function to add a range of numbers
    template <typename InputIterator>
    void addRange(InputIterator first, InputIterator last); // Implementation moved to Span.tpp

    long shortestSpan() const; // Changed to long to handle potential INT_MAX - INT_MIN
    long longestSpan() const;  // Changed to long

    // Helper to get access to the underlying vector for testing or other purposes if needed
    const std::vector<int>& getNumbers() const;
    unsigned int getMaxSize() const;
    unsigned int getCurrentSize() const;

    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Span is full. Cannot add more numbers.";
        }
    };

    class NotEnoughElementsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Not enough elements to find a span (requires at least 2).";
        }
    };
};

#include "Span.tpp" // For template definitions

#endif // SPAN_HPP
