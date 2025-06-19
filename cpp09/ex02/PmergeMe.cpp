#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

PmergeMe::PmergeMe(std::vector<int> inputElements) : m_vec(inputElements), m_deq(inputElements.begin(), inputElements.end())
{
    std::cout << "Before: ";
    unsigned int len = inputElements.size();
    for (unsigned int i = 0; i < len; i++)
        std::cout << inputElements[i] << " ";
    std::cout << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const& example) : m_vec(example.m_vec), m_deq(example.m_vec.begin(), example.m_vec.end())
{
    std::cout << "PmergeMe Copy Constructor" << std::endl;
}

PmergeMe& PmergeMe::operator=(PmergeMe& example) 
{
    if (this != &example)
    {
        m_vec = example.m_vec;
        std::vector<int>::iterator it = example.m_vec.begin();
        std::vector<int>::iterator end = example.m_vec.end();
        while (it != end)
            m_deq.push_back(*it);
    }
    std::cout << "PmergeMe Operator = Overload" << std::endl;
    return *this;
}

PmergeMe::~PmergeMe() {}


//down below you will see code duplicated, the subject here explicitely refrained us from using templates
std::vector<int>& PmergeMe::getVector() { return m_vec; }

void PmergeMe::insertElementVec(std::vector<int>::iterator pos, int element, std::vector<int>& container)
{
    container.insert(pos, element);
}

std::vector<std::pair<int, int> > pairUpVec(std::vector<int>& container)
{
    unsigned int len = container.size();
    unsigned int amountOfPairs;
    unsigned int i = 0; unsigned int j = 0;
    amountOfPairs = len / 2;

    std::vector<std::pair<int, int> > test;
    while (i < container.size() && j < amountOfPairs)
    {
        test.push_back(std::make_pair(container[i], container[i+1]));
        i+=2, j++;
    }
    return test;
}

std::vector<int> pushLargeVec(std::vector<std::pair<int, int> > &doubleDim, std::vector<int>& container)
{
    std::vector<int> largeElems;
    for (unsigned int j = 0; j < doubleDim.size(); j++)
    {
            if (doubleDim[j].first < doubleDim[j].second)
                largeElems.push_back(doubleDim[j].second);
            else
                largeElems.push_back(doubleDim[j].first);
    }
    if (container.size() % 2 != 0)
        largeElems.push_back(container[container.size() - 1]);
    return largeElems;
    
}

std::vector<int> pushSmallVec(std::vector<std::pair<int, int> > &doubleDim)
{
    std::vector<int> smallElems;
    for (unsigned int j = 0; j < doubleDim.size(); j++)
    {
            if (doubleDim[j].first < doubleDim[j].second)
                smallElems.push_back(doubleDim[j].first);
            else
                smallElems.push_back(doubleDim[j].second);
    }
    return smallElems;
    
}

void PmergeMe::sortElementsVec()
{
    std::vector<std::pair<int, int> > doubleDim_Vec = pairUpVec(m_vec);                   //x1 
    
    //separating pairs into a vector of larger numbers and another one of small numbers
    std::vector<int> largeElementVec = pushLargeVec(doubleDim_Vec, m_vec);                   //templates 
    std::vector<int> smallElementVect = pushSmallVec(doubleDim_Vec);
    std::sort(largeElementVec.begin(), largeElementVec.end());

    for (unsigned int i = 0; i < smallElementVect.size(); i++)
    {
        //function from algorithm to find lower-bound index
        std::vector<int>::iterator pos = std::lower_bound(largeElementVec.begin(), largeElementVec.end(), smallElementVect[i]);
        this->insertElementVec(pos, smallElementVect[i], largeElementVec);
    }
    std::swap(m_vec, largeElementVec);
}

void PmergeMe::printSortedVec()
{
    std::vector<int>::iterator it = m_vec.begin();
    std::vector<int>::iterator end = m_vec.end();
    std::cout << "After: ";
    while (it != end)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

//sorry for this duplicate, the subject explicitely refrains us from using templates
std::deque<int>& PmergeMe::getDeque() { return m_deq; }

void PmergeMe::insertElementDeq(std::deque<int>::iterator pos, int element, std::deque<int>& container)
{
    container.insert(pos, element);
}

std::deque<std::pair<int, int> > pairUpDeq(std::deque<int>& container)
{
    unsigned int len = container.size();
    unsigned int amountOfPairs;
    unsigned int i = 0; unsigned int j = 0;
    amountOfPairs = len / 2;

    std::deque<std::pair<int, int> > test;
    while (i < container.size() && j < amountOfPairs)
    {
        test.push_back(std::make_pair(container[i], container[i+1]));
        i+=2, j++;
    }
    return test;
}

std::deque<int> pushLargeDeq(std::deque<std::pair<int, int> > &doubleDim, std::deque<int>& container)
{
    std::deque<int> largeElems;
    for (unsigned int j = 0; j < doubleDim.size(); j++)
    {
            if (doubleDim[j].first < doubleDim[j].second)
                largeElems.push_back(doubleDim[j].second);
            else
                largeElems.push_back(doubleDim[j].first);
    }
    if (container.size() % 2 != 0)
        largeElems.push_back(container[container.size() - 1]);
    return largeElems;
    
}

std::deque<int> pushSmallDeq(std::deque<std::pair<int, int> > &doubleDim)
{
    std::deque<int> smallElems;
    for (unsigned int j = 0; j < doubleDim.size(); j++)
    {
            if (doubleDim[j].first < doubleDim[j].second)
                smallElems.push_back(doubleDim[j].first);
            else
                smallElems.push_back(doubleDim[j].second);
    }
    return smallElems;
    
}

void PmergeMe::sortElementsDeq()
{
    std::deque<std::pair<int, int> > doubleDim_Deq = pairUpDeq(m_deq);                   //x1 
    
    //separating pairs into a deque of larger numbers and another one of small numbers
    std::deque<int> largeElementDeq = pushLargeDeq(doubleDim_Deq, m_deq);                   //templates 
    std::deque<int> smallElementDeq = pushSmallDeq(doubleDim_Deq);
    std::sort(largeElementDeq.begin(), largeElementDeq.end());

    for (unsigned int i = 0; i < smallElementDeq.size(); i++)
    {
        //function from algorithm to find lower-bound index
        std::deque<int>::iterator pos = std::lower_bound(largeElementDeq.begin(), largeElementDeq.end(), smallElementDeq[i]);
        this->insertElementDeq(pos, smallElementDeq[i], largeElementDeq);
    }
    std::swap(m_deq, largeElementDeq);
}

void PmergeMe::printSortedDeq()
{
    std::deque<int>::iterator it = m_deq.begin();
    std::deque<int>::iterator end = m_deq.end();
    std::cout << "After: ";
    while (it != end)
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
}

const char* PmergeMe::negativeNumber::what() const throw()
{
    return ("Error: numbers passed as args cannot be negative");
}

const char* PmergeMe::badInput::what() const throw()
{
    return ("Error: the input can only hold digits");
}

