#include "iter.hpp"
#include <iostream>
#include <string>
#include <cctype> // For toupper

// Template function to print any element
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// Function to increment an integer
void incrementElement(int& n) {
    n++;
}

// Function to append a star to a string
void appendStar(std::string& s) {
    s += "*";
}

// Function to convert a char to uppercase
void toUpperCase(char& c) {
    c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

// A simple class for testing with custom types
class MyClass {
public:
    int value;
    MyClass(int v = 0) : value(v) {}
};

// Overload << for MyClass for printing
std::ostream& operator<<(std::ostream& os, const MyClass& mc) {
    os << "MyClass(" << mc.value << ")";
    return os;
}

// Function to modify MyClass object (example)
void incrementMyClassValue(MyClass& mc) {
    mc.value += 10;
}


int main() {
    // Test with an array of integers
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intArrLen = sizeof(intArr) / sizeof(int);

    std::cout << "Original int array: ";
    iter(intArr, intArrLen, printElement<int>);
    std::cout << std::endl;

    iter(intArr, intArrLen, incrementElement);
    std::cout << "Int array after increment: ";
    iter(intArr, intArrLen, printElement<int>);
    std::cout << std::endl << std::endl;

    // Test with an array of strings
    std::string strArr[] = {"hello", "world", "cpp", "07"};
    size_t strArrLen = sizeof(strArr) / sizeof(std::string);

    std::cout << "Original string array: ";
    iter(strArr, strArrLen, printElement<std::string>);
    std::cout << std::endl;

    iter(strArr, strArrLen, appendStar);
    std::cout << "String array after appendStar: ";
    iter(strArr, strArrLen, printElement<std::string>);
    std::cout << std::endl << std::endl;

    // Test with an array of characters
    char charArr[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrLen = sizeof(charArr) / sizeof(char);

    std::cout << "Original char array: ";
    iter(charArr, charArrLen, printElement<char>);
    std::cout << std::endl;

    iter(charArr, charArrLen, toUpperCase);
    std::cout << "Char array after toUpperCase: ";
    iter(charArr, charArrLen, printElement<char>);
    std::cout << std::endl << std::endl;
    
    // Test with an array of floats
    float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t floatArrLen = sizeof(floatArr) / sizeof(float);

    std::cout << "Original float array: ";
    iter(floatArr, floatArrLen, printElement<float>);
    std::cout << std::endl << std::endl;

    // Test with an array of custom class objects
    MyClass myClassArr[] = {MyClass(1), MyClass(2), MyClass(3)};
    size_t myClassArrLen = sizeof(myClassArr) / sizeof(MyClass);

    std::cout << "Original MyClass array: ";
    iter(myClassArr, myClassArrLen, printElement<MyClass>);
    std::cout << std::endl;

    iter(myClassArr, myClassArrLen, incrementMyClassValue);
    std::cout << "MyClass array after incrementMyClassValue: ";
    iter(myClassArr, myClassArrLen, printElement<MyClass>);
    std::cout << std::endl << std::endl;

    // Test with an empty array (using NULL pointer and length 0)
    int* emptyArr = NULL; // Using NULL for empty array representation
    size_t emptyArrLen = 0;
    std::cout << "Testing with empty int array (NULL pointer, length 0): ";
    iter(emptyArr, emptyArrLen, printElement<int>); // Should not crash or print anything for elements
    iter(emptyArr, emptyArrLen, incrementElement); // Should also not crash
    std::cout << "(should be empty)" << std::endl << std::endl;

    // Test with NULL pointer (optional, iter handles this)
    int* nullArr = NULL;
    std::cout << "Testing with NULL int array pointer: ";
    iter(nullArr, 5, printElement<int>); // Should not crash
    std::cout << "(should be empty/no output)" << std::endl;


    return 0;
}
