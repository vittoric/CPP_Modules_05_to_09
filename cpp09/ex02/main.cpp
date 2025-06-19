#include <iostream>
#include "PmergeMe.hpp"
#include <sstream>
#include <sys/time.h>

int strToNum(std::string str)
{
    int result;
    std::istringstream convert(str);
    if (convert.fail())
        throw PmergeMe::badInput();
    convert >> result;
    return result;
}


std::vector<int> parseElements(char **argv, int argc)
{
    std::vector<int> inputElements;
    for (int i = 1; i < argc; i++)
    {
        int num = strToNum(argv[i]);
        if (num < 0)
        {
            throw PmergeMe::negativeNumber();
        }
        inputElements.push_back(num);
    }
    return inputElements;
}

void printSortingTime(int start, int end, int argc, std::string type)
{
    std::cout << "Time to process a range of " << argc - 1 << " elements with " << type << ": ";
    std::cout << (end - start)/double(CLOCKS_PER_SEC)*1000;
    std::cout << " us" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try {
        int start = clock() ; 
        std::vector<int> inputElements = parseElements(argv, argc);
        PmergeMe obj(inputElements);

        obj.sortElementsVec();
        int stop_Vec = clock(); 
        obj.sortElementsDeq();
        int stop_Deq = clock(); 

        obj.printSortedVec();
        printSortingTime(start,stop_Vec, argc, "std::vector");
        printSortingTime(start,stop_Deq, argc, "std::deque");
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
