#include <iostream>
#include "Array.hpp" // Corrected include path
#include <cstdlib>  // For rand(), srand()
#include <ctime>    // For time()
#include <stdexcept> // For std::exception (if Array throws it directly)

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers; // Tests copy constructor or assignment then copy
        Array<int> test(tmp);     // Tests copy constructor
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0; // This will be cast to a large unsigned int
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // This loop in the provided main might be for further testing or was part of a larger test.
    // It re-randomizes 'numbers' but doesn't check against 'mirror' afterwards.
    // For the purpose of this exercise, it's fine.
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "Successfully completed tests without crashing (mirror check passed, exceptions caught)." << std::endl;
    std::cout << "Note: The last loop re-randomizes 'numbers' array; no check against 'mirror' is performed for these new values." << std::endl;
    
    delete [] mirror;
    return 0;
}
