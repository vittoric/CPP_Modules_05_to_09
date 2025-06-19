#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int evaluate(const std::string& expression);

private:
    std::stack<int> _stack;

    void _executeOperation(char op);
    bool _isOperator(char c);
    int _stringToInteger(const std::string& s);
};

#endif // RPN_HPP
