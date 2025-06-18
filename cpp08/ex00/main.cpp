#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
void testContainer(T& container, int valueToFind, const std::string& containerName) {
    std::cout << "Testing " << containerName << "..." << std::endl;
    // Add some elements to the container
    for (int i = 1; i <= 5; ++i) {
        container.push_back(i * 10);
    }
    // Add a specific value to find if it's not already there by chance
    if (valueToFind % 10 != 0) {
         container.push_back(valueToFind);
    }


    std::cout << "Container elements: ";
    for (typename T::iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    try {
        typename T::iterator result = easyfind(container, valueToFind);
        std::cout << "Found " << valueToFind << " at position: " << std::distance(container.begin(), result) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << ": " << valueToFind << " not found." << std::endl;
    }

    // Test with a value that is not in the container
    int valueNotFound = 99;
    std::cout << "Trying to find " << valueNotFound << "..." << std::endl;
    try {
        easyfind(container, valueNotFound);
        std::cout << "Found " << valueNotFound << " (this should not happen)" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << ": " << valueNotFound << " not found." << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}

int main() {
    std::vector<int> myVector;
    testContainer(myVector, 30, "std::vector");

    std::list<int> myList;
    testContainer(myList, 20, "std::list");

    std::deque<int> myDeque;
    testContainer(myDeque, 50, "std::deque");
    
    // Test with a value that will be added
    std::vector<int> myVector2;
    testContainer(myVector2, 25, "std::vector with custom value");

    return 0;
}
