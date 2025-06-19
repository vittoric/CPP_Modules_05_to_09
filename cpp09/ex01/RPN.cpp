#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
    _stack = other._stack;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (_isOperator(token[0]) && token.length() == 1) {
            if (_stack.size() < 2) {
                throw std::runtime_error("Error: Not enough operands for operator");
            }
            _executeOperation(token[0]);
        } else {
            try {
                _stack.push(_stringToInteger(token));
            } catch (const std::invalid_argument& e) {
                throw std::runtime_error("Error: Invalid token");
            }
        }
    }

    if (_stack.size() != 1) {
        throw std::runtime_error("Error: Invalid expression");
    }

    int result = _stack.top();
    _stack.pop(); // Clear stack for next evaluation if any
    return result;
}

void RPN::_executeOperation(char op) {
    int val2 = _stack.top();
    _stack.pop();
    int val1 = _stack.top();
    _stack.pop();

    switch (op) {
        case '+':
            _stack.push(val1 + val2);
            break;
        case '-':
            _stack.push(val1 - val2);
            break;
        case '*':
            _stack.push(val1 * val2);
            break;
        case '/':
            if (val2 == 0) {
                throw std::runtime_error("Error: Division by zero");
            }
            _stack.push(val1 / val2);
            break;
        default:
            // Should not happen if _isOperator is comprehensive
            throw std::runtime_error("Error: Unknown operator"); 
    }
}

bool RPN::_isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::_stringToInteger(const std::string& s) {
    if (s.length() != 1 || !isdigit(s[0])) {
        throw std::invalid_argument("Error: Invalid number token");
    }
    int value = s[0] - '0'; // Convert char to int

    // The problem states "a positive integer lower than 10".
    // This implies 0, 1, 2, ..., 9.
    // The isdigit check already ensures it's a digit.
    // No specific check for < 0 is needed if isdigit passed and s[0] - '0' is used.
    // The value >= 10 is implicitly handled by length check (e.g. "10" is length 2).
    // However, re-instating the explicit range check for clarity and safety is fine.
    if (value < 0 || value > 9) { // Should ideally not be hit if logic above is sound
        throw std::invalid_argument("Error: Number out of range (0-9)");
    }
    return value;
}
