#include <iostream>  // For std::cout
#include <cstdlib>   // For rand, srand (used in main for seeding)
#include <ctime>     // For time (used in main for seeding)
#include <exception> // For std::bad_cast (as per prompt, though not directly used in main now)

#include "Identify.hpp" // Includes Base.hpp, A.hpp, B.hpp, C.hpp and function declarations
// Note: Base.hpp, A.hpp etc. are not directly included here anymore, they come via identify.hpp


int main() {
    // Seed the random number generator (as per original main.cpp)
    // generate() itself is now in identify.cpp but srand() is typically called once in main.
    srand(static_cast<unsigned int>(time(NULL)));

    std::cout << "--- Testing with 10 random instances ---" << std::endl;
    for (int i = 0; i < 10; ++i) {
        Base* instance = generate(); // generate() is now an external function
        if (instance) {
            // The output messages in identify functions were changed slightly in the prompt
            // for identify.cpp, so the main.cpp output here is simplified.
            identify(instance);    // identify(Base* p)
            identify(*instance);   // identify(Base& p)
            delete instance;
        } else {
            std::cout << "generate() returned NULL (should not happen with current impl)" << std::endl;
        }
        if (i < 9) { // Add a separator for all but the last iteration for clarity
             std::cout << "--------------------" << std::endl;
        }
    }
    
    std::cout << "\n\n--- Testing identify(Base* p) with NULL ---" << std::endl;
    identify(static_cast<Base*>(NULL)); // identify(Base* p)

    std::cout << "\n\n--- Testing with Base object itself (demonstrating fallback) ---" << std::endl;
    Base base_obj; // Base is not abstract
    identify(&base_obj); // identify(Base* p)
    identify(base_obj);  // identify(Base& p)

    return 0;
}
