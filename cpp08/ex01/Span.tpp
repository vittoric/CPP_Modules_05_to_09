#ifndef SPAN_TPP
#define SPAN_TPP

// It's generally good practice to include the header that declares what this .tpp implements,
// or at least the necessary dependencies if not already pulled by Span.hpp for the implementation details.
// However, since Span.hpp includes this, and Span.hpp has the class definition, we just need 
// to provide the template definition.
// #include "Span.hpp" // Usually good, but creates circular dependency if Span.hpp includes Span.tpp at the end.
                      // Not strictly needed here as Span.hpp is expected to be included before this by the compiler
                      // when main.cpp (or other .cpp) includes Span.hpp

#include <vector>    // For std::vector, used by _numbers
#include <iterator>  // For std::distance
#include <stdexcept> // For std::length_error
// Span.hpp itself should include <vector> and <stdexcept> if the class declaration needs them,
// which it does for std::vector _numbers and the custom exceptions deriving from std::exception.
// algorithm is also in Span.hpp, numeric for std::distance is also there.

// Template member function implementation
template <typename InputIterator>
void Span::addRange(InputIterator first, InputIterator last) {
    // Check if there's enough space
    // Note: std::distance can be O(N) for input iterators that are not random access.
    // If performance with non-random-access iterators is critical and N is large,
    // one might need a different approach or to document this behavior.
    
    // Using size_t for size comparisons is typical. std::distance returns a difference_type,
    // which is usually a signed type. Ensure types are compatible for comparison.
    typename std::iterator_traits<InputIterator>::difference_type count = std::distance(first, last);
    if (count < 0) {
        // This case should ideally not happen with valid ranges (first before last)
        // but good to be aware of if iterators could be misordered.
        // Or, if std::distance could return negative for some other reason.
        // For this exercise, assume valid ranges where count >= 0.
        throw std::invalid_argument("Invalid iterator range for addRange.");
    }

    if (_numbers.size() + static_cast<size_t>(count) > _maxSize) {
        throw std::length_error("Cannot add range: Span will exceed maximum size.");
    }
    // Use vector's insert method to add the elements from the iterator range
    _numbers.insert(_numbers.end(), first, last);
}

#endif // SPAN_TPP
