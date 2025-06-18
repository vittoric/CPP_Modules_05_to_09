#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm> // for std::generate, std::sort
#include <cstdlib>   // for rand, srand
#include <ctime>     // for time
#include <limits>    // For std::numeric_limits (though not directly used here, good include for number context)

// Helper function to print container elements (optional)
void printNumbers(const Span& sp) {
    const std::vector<int>& nums = sp.getNumbers();
    if (nums.empty()) {
        std::cout << "(empty)" << std::endl;
        return;
    }
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }
    std::cout << " (Size: " << sp.getCurrentSize() << "/" << sp.getMaxSize() << ")" << std::endl;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for rand()

    // Test 1: Subject's example
    std::cout << "--- Test 1: Subject's Example ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Span content: "; printNumbers(sp);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl; // Expected: 2
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;   // Expected: 14
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "---------------------------------" << std::endl;

    // Test 2: Adding Numbers & Full Span Exception
    std::cout << "\n--- Test 2: Adding Numbers & Full Span ---" << std::endl;
    try {
        Span sp2 = Span(3);
        std::cout << "Initial span: "; printNumbers(sp2);
        sp2.addNumber(1);
        std::cout << "After adding 1: "; printNumbers(sp2);
        sp2.addNumber(2);
        std::cout << "After adding 2: "; printNumbers(sp2);
        sp2.addNumber(3);
        std::cout << "After adding 3 (full): "; printNumbers(sp2);
        std::cout << "Span current size: " << sp2.getCurrentSize() << "/" << sp2.getMaxSize() << std::endl;
        std::cout << "Trying to add one more number to a full Span..." << std::endl;
        sp2.addNumber(4); // This should throw SpanFullException
    } catch (const Span::SpanFullException& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;

    // Test 3: Not Enough Elements Exception
    std::cout << "\n--- Test 3: Not Enough Elements ---" << std::endl;
    try {
        Span sp3 = Span(5);
        std::cout << "Span content: "; printNumbers(sp3);
        std::cout << "Shortest span on empty: ";
        std::cout << sp3.shortestSpan() << std::endl; // Should throw NotEnoughElementsException
    } catch (const Span::NotEnoughElementsException& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    try {
        Span sp4 = Span(5);
        sp4.addNumber(100);
        std::cout << "Span content: "; printNumbers(sp4);
        std::cout << "Longest span with one element: ";
        std::cout << sp4.longestSpan() << std::endl; // Should throw NotEnoughElementsException
    } catch (const Span::NotEnoughElementsException& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    // Test 4: Using addRange
    std::cout << "\n--- Test 4: Using addRange ---" << std::endl;
    try {
        Span sp5 = Span(10);
        std::vector<int> vec;
        for (int i = 0; i < 5; ++i) vec.push_back(i * 5); // 0, 5, 10, 15, 20
        
        std::cout << "Adding vector {0, 5, 10, 15, 20} to Span(10)" << std::endl;
        sp5.addRange(vec.begin(), vec.end());
        std::cout << "Span after addRange from vector: "; printNumbers(sp5);
        std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl; // Expected: 5
        std::cout << "Longest span: " << sp5.longestSpan() << std::endl;   // Expected: 20

        std::list<int> lst;
        for (int i = 0; i < 3; ++i) lst.push_back(100 + i * 2); // 100, 102, 104
        
        std::cout << "Adding list {100, 102, 104} to Span (current size 5/10)" << std::endl;
        sp5.addRange(lst.begin(), lst.end()); 
        std::cout << "Span after addRange from list: "; printNumbers(sp5); // Now 8 elements
        // Content: 0, 5, 10, 15, 20, 100, 102, 104. Sorted: same.
        // Shortest: 2 (102-100 or 104-102) or 5. Min is 2.
        // Longest: 104-0 = 104.
        std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl; // Expected: 2
        std::cout << "Longest span: " << sp5.longestSpan() << std::endl;   // Expected: 104

        std::deque<int> deq;
        for (int i = 0; i < 3; ++i) deq.push_back(200 + i); // 200, 201, 202. Size 3. Current 8. Max 10. 8+3 > 10.
        
        std::cout << "Trying to add deque {200, 201, 202} which would exceed capacity (8+3 > 10)..." << std::endl;
        sp5.addRange(deq.begin(), deq.end()); // This should throw std::length_error

    } catch (const std::length_error& e) { 
        std::cerr << "Caught expected std::length_error: " << e.what() << std::endl;
    } catch (const Span::SpanFullException& e) { 
        std::cerr << "Caught SpanFullException (should be std::length_error for addRange per hpp): " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }
    std::cout << "----------------------------" << std::endl;


    // Test 5: Large Number Test (15,000 numbers)
    std::cout << "\n--- Test 5: Large Number Test (15,000) ---" << std::endl;
    try {
        unsigned int numElements = 15000;
        Span spLarge = Span(numElements);
        std::vector<int> largeVec;
        largeVec.reserve(numElements);
        std::cout << "Generating " << numElements << " random numbers for large test..." << std::endl;
        for (unsigned int i = 0; i < numElements; ++i) {
            largeVec.push_back(rand()); 
        }
        
        spLarge.addRange(largeVec.begin(), largeVec.end());
        std::cout << "Added " << spLarge.getCurrentSize() << " random numbers." << std::endl;
        // printNumbers(spLarge); // Probably too much to print
        
        std::cout << "Calculating shortest span for large data set..." << std::endl;
        long sSpan = spLarge.shortestSpan();
        std::cout << "Shortest span: " << sSpan << std::endl;

        std::cout << "Calculating longest span for large data set..." << std::endl;
        long lSpan = spLarge.longestSpan();
        std::cout << "Longest span: " << lSpan << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception in large number test: " << e.what() << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
    
    // Test 6: Test with negative numbers and duplicates
    std::cout << "\n--- Test 6: Negative numbers and Duplicates ---" << std::endl;
    try {
        Span spMixed = Span(10);
        spMixed.addNumber(-5);
        spMixed.addNumber(10);
        spMixed.addNumber(0);
        spMixed.addNumber(-5); // Duplicate
        spMixed.addNumber(100);
        spMixed.addNumber(50);
        std::cout << "Span content: "; printNumbers(spMixed);
        // Sorted: -5, -5, 0, 10, 50, 100
        // Diffs: 0, 5, 10, 40, 50. Shortest: 0.
        // Longest: 100 - (-5) = 105.
        std::cout << "Shortest span (mixed): " << spMixed.shortestSpan() << std::endl;
        std::cout << "Longest span (mixed): " << spMixed.longestSpan() << std::endl;  
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "\nAll tests complete." << std::endl;

    return 0;
}
