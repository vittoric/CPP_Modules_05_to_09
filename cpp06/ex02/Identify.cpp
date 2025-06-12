#include "Identify.hpp"


// generate() implementation
Base* generate(void) {
    int choice = rand() % 3;
    if (choice == 0) {
        std::cout << "Generated: A" << std::endl;
        return new A();
    } else if (choice == 1) {
        std::cout << "Generated: B" << std::endl;
        return new B();
    } else {
        std::cout << "Generated: C" << std::endl;
        return new C();
    }
}

// identify(Base* p) implementation
void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Identified by pointer: Pointer is NULL" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p)) {
        std::cout << "Identified by pointer: A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Identified by pointer: B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Identified by pointer: C" << std::endl;
    } else {
        std::cout << "Identified by pointer: Unknown type (not A, B, or C, or actual Base)" << std::endl;
    }
}

// identify(Base& p) implementation
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p); // Attempt to cast to A&
        std::cout << "Identified by reference: A" << std::endl;
        return;
    } catch (const std::exception& e) { // Catching std::exception as std::bad_cast inherits from it
        // Cast to A& failed, try B&
    }

    try {
        (void)dynamic_cast<B&>(p); // Attempt to cast to B&
        std::cout << "Identified by reference: B" << std::endl;
        return;
    } catch (const std::exception& e) { // Catching std::exception
        // Cast to B& failed, try C&
    }

    try {
        (void)dynamic_cast<C&>(p); // Attempt to cast to C&
        std::cout << "Identified by reference: C" << std::endl;
        return;
    } catch (const std::exception& e) { // Catching std::exception
        // Cast to C& failed
    }
    // If all casts failed
    std::cout << "Identified by reference: Unknown type (not A, B, or C, or actual Base)" << std::endl;
}
