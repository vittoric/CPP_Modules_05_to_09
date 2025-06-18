#include "Span.hpp"
#include <algorithm> // For std::sort, std::min_element, std::max_element
#include <vector>
// #include <stdexcept> // Not strictly needed here if exceptions defined in Span.hpp are self-contained
                     // or if Span.hpp already includes what's needed for std::exception base.
                     // Span.hpp includes <stdexcept> so it's fine.
#include <limits> // Required for std::numeric_limits

// Constructor
Span::Span(unsigned int N) : _maxSize(N) {
    // _numbers is implicitly default-initialized (empty vector)
    // _numbers.reserve(N); // Optional: can be added for performance optimization
}

// Copy Constructor
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {
}

// Assignment Operator
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers; // std::vector handles its own memory
    }
    return *this;
}

// Destructor
Span::~Span() {
    // std::vector handles its own memory, so no explicit cleanup needed here
}

// addNumber
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw Span::SpanFullException();
    }
    _numbers.push_back(number);
}

// shortestSpan
long Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw Span::NotEnoughElementsException();
    }

    std::vector<int> sortedNumbers = _numbers; // Make a copy to sort
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    long minSpan = std::numeric_limits<long>::max();

    // Ensure there are at least two elements after sorting for the loop to be safe
    // The check _numbers.size() < 2 already guarantees this.
    for (size_t i = 0; i < sortedNumbers.size() - 1; ++i) {
        long currentSpan = static_cast<long>(sortedNumbers[i+1]) - static_cast<long>(sortedNumbers[i]);
        if (currentSpan < minSpan) {
            minSpan = currentSpan;
        }
    }
    return minSpan;
}

// longestSpan
long Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw Span::NotEnoughElementsException();
    }

    // Finding min and max element is O(N) each.
    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<long>(*maxIt) - static_cast<long>(*minIt);
}

// Getter implementations
const std::vector<int>& Span::getNumbers() const {
    return _numbers;
}

unsigned int Span::getMaxSize() const {
    return _maxSize;
}

unsigned int Span::getCurrentSize() const {
    return _numbers.size();
}

// Note: The addRange template function is implemented in Span.hpp
// Default constructor Span() is private and not defined as it's not used in Span.cpp
// (It's declared in Span.hpp as private).
