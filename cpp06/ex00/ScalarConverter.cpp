#include "ScalarConverter.hpp"

// Constructores y destructor privados
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

// Método principal de conversión
void ScalarConverter::convert(const std::string& literal) {
    if (literal.empty()) {
        std::cout << "Error: Empty input" << std::endl;
        return;
    }

    // Detectar el tipo y convertir
    if (isPseudoLiteral(literal)) {
        convertFromPseudoLiteral(literal);
    } else if (isChar(literal)) {
        convertFromChar(literal[1]); // El formato es 'c'
    } else if (isInt(literal)) {
        convertFromInt(std::atoi(literal.c_str()));
    } else if (isFloat(literal)) {
        convertFromFloat(std::atof(literal.c_str()));
    } else if (isDouble(literal)) {
        convertFromDouble(std::atof(literal.c_str()));
    } else {
        std::cout << "Error: Invalid input type" << std::endl;
    }
}

// Métodos para detectar el tipo
bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

bool ScalarConverter::isInt(const std::string& literal) {
    if (literal.empty()) return false;
    
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-') i++;
    
    for (; i < literal.length(); i++) {
        if (!std::isdigit(literal[i])) return false;
    }
    
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal.empty()) return false;
    
    // Verificar si termina con 'f'
    if (literal[literal.length() - 1] != 'f') return false;
    
    // Verificar si es un pseudo-literal float
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") return true;
    
    // Verificar si es un número float válido
    size_t i = 0;
    bool hasDecimalPoint = false;
    
    if (literal[0] == '+' || literal[0] == '-') i++;
    
    for (; i < literal.length() - 1; i++) {
        if (literal[i] == '.') {
            if (hasDecimalPoint) return false; // No puede tener más de un punto decimal
            hasDecimalPoint = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    
    return hasDecimalPoint; // Debe tener al menos un punto decimal
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal.empty()) return false;
    
    // Verificar si es un pseudo-literal double
    if (literal == "nan" || literal == "+inf" || literal == "-inf") return true;
    
    // Verificar si es un número double válido
    size_t i = 0;
    bool hasDecimalPoint = false;
    
    if (literal[0] == '+' || literal[0] == '-') i++;
    
    for (; i < literal.length(); i++) {
        if (literal[i] == '.') {
            if (hasDecimalPoint) return false; // No puede tener más de un punto decimal
            hasDecimalPoint = true;
        } else if (!std::isdigit(literal[i])) {
            return false;
        }
    }
    
    return hasDecimalPoint; // Debe tener al menos un punto decimal
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return (literal == "nan" || literal == "+inf" || literal == "-inf" ||
            literal == "nanf" || literal == "+inff" || literal == "-inff");
}

// Métodos de conversión según el tipo detectado
void ScalarConverter::convertFromChar(char c) {
    std::cout << "char: ";
    if (std::isprint(c)) {
        std::cout << "'" << c << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
    
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int i) {
    std::cout << "char: ";
    if (i >= 0 && i <= 127) {
        if (std::isprint(i)) {
            std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
    } else {
        std::cout << "impossible" << std::endl;
    }
    
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(float f) {
    std::cout << "char: ";
    if (std::isnan(f) || std::isinf(f)) {
        std::cout << "impossible" << std::endl;
    } else if (f >= 0 && f <= 127) {
        if (std::isprint(static_cast<int>(f))) {
            std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
    } else {
        std::cout << "impossible" << std::endl;
    }
    
    std::cout << "int: ";
    if (std::isnan(f) || std::isinf(f) || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(f) << std::endl;
    }
    
    // Para mostrar .0 solo cuando es un número entero
    if (f == static_cast<int>(f)) {
        std::cout << "float: " << f << ".0f" << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
    }
    
    if (f == static_cast<int>(f)) {
        std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
    } else {
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
}

void ScalarConverter::convertFromDouble(double d) {
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d)) {
        std::cout << "impossible" << std::endl;
    } else if (d >= 0 && d <= 127) {
        if (std::isprint(static_cast<int>(d))) {
            std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
    } else {
        std::cout << "impossible" << std::endl;
    }
    
    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << static_cast<int>(d) << std::endl;
    }
    
    std::cout << "float: ";
    if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        // Para mostrar .0 solo cuando es un número entero
        if (d == static_cast<int>(d)) {
            std::cout << static_cast<float>(d) << ".0f" << std::endl;
        } else {
            std::cout << static_cast<float>(d) << "f" << std::endl;
        }
    }
    
    // Para mostrar .0 solo cuando es un número entero
    if (d == static_cast<int>(d)) {
        std::cout << "double: " << d << ".0" << std::endl;
    } else {
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convertFromPseudoLiteral(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "float: " << literal << std::endl;
        // Convertir a formato double (quitar la 'f')
        std::string doubleLiteral = literal.substr(0, literal.length() - 1);
        std::cout << "double: " << doubleLiteral << std::endl;
    } else { // nan, +inf, -inf
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
}