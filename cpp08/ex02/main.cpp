#include "MutantStack.hpp"
#include <iostream>
#include <list> // For testing with a different container and comparing behavior
#include <vector> // Required for std::vector container type

void subject_test() {
    std::cout << "--- Subject's Test ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl; // Expected: 17
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl; // Expected: 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "Iterating MutantStack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    // Expected output for iteration: 5, 3, 5, 737, 0 (assuming pop was on 17, then 5 was the old top)
    // Stack after operations:
    // top -> 0
    //      737
    //      5
    //      3
    //      5  (original 5 at the bottom)
    // So, begin() should point to 5 (bottom), end() past 0.

    std::cout << "\nCopying to std::stack (for conceptual comparison of iteration)" << std::endl;
    std::stack<int> s(mstack); // Copy constructor test
    // std::stack s does not have iterators, so we can't iterate it directly this way.
    // The subject's main is demonstrating that MutantStack can be treated as a std::stack
    // but also has iterators.
    std::cout << "MutantStack copied to std::stack (size: " << s.size() << ")" << std::endl;
    if (!s.empty()) {
        std::cout << "Top of copied std::stack: " << s.top() << std::endl;
    }
    std::cout << "----------------------" << std::endl;
}

void list_comparison_test() {
    std::cout << "\n--- List Comparison Test ---" << std::endl;
    std::list<int> list;
    list.push_back(5); // Equivalent to stack's bottom
    list.push_back(17);
    std::cout << "List top (back): " << list.back() << std::endl;
    list.pop_back(); // Removes 17
    std::cout << "List size after pop_back: " << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0); // 0 is now at the back (top)

    std::cout << "Iterating std::list:" << std::endl;
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
}

void extended_tests() {
    std::cout << "\n--- Extended MutantStack Tests ---" << std::endl;
    MutantStack<std::string> strStack;
    std::cout << "Is string stack empty? " << (strStack.empty() ? "Yes" : "No") << std::endl;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("Test");

    std::cout << "String stack (top to bottom using iterators):" << std::endl;
    // Iterators go from bottom to top (begin to end)
    // To print top to bottom, use reverse iterators or iterate and store then print reverse
    // Let's print begin to end (bottom to top)
    std::cout << "Bottom to top:" << std::endl;
    for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it) {
        std::cout << *it << std::endl;
    }
    
    std::cout << "\nUsing const_iterator:" << std::endl;
    const MutantStack<std::string>& constStrStack = strStack;
    for (MutantStack<std::string>::const_iterator cit = constStrStack.begin(); cit != constStrStack.end(); ++cit) {
        std::cout << *cit << std::endl;
    }

    std::cout << "\nUsing reverse_iterator (top to bottom):" << std::endl;
    for (MutantStack<std::string>::reverse_iterator rit = strStack.rbegin(); rit != strStack.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }
    
    std::cout << "\nPop elements:" << std::endl;
    while(!strStack.empty()) {
        std::cout << "Popping: " << strStack.top() << std::endl;
        strStack.pop();
    }
    std::cout << "Is string stack empty after pops? " << (strStack.empty() ? "Yes" : "No") << std::endl;

    // Test with a different container (std::vector)
    MutantStack<int, std::vector<int> > mstack_vector;
    mstack_vector.push(10);
    mstack_vector.push(20);
    mstack_vector.push(30);
    std::cout << "\nMutantStack with std::vector as container (bottom to top):" << std::endl;
    for (MutantStack<int, std::vector<int> >::iterator it = mstack_vector.begin(); it != mstack_vector.end(); ++it) {
        std::cout << *it << std::endl;
    }
    std::cout << "Top: " << mstack_vector.top() << std::endl;
    std::cout << "------------------------------" << std::endl;
}


int main() {
    subject_test();
    list_comparison_test(); // To show underlying deque behaves like list for iteration
    extended_tests();
    return 0;
}
