#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter {
    private:
        // Constructor privado para evitar instanciación
        ScalarConverter();
        // Constructor de copia privado
        ScalarConverter(const ScalarConverter& other);
        // Operador de asignación privado
        ScalarConverter& operator=(const ScalarConverter& other);
        // Destructor privado
        ~ScalarConverter();

        // Métodos auxiliares para detectar el tipo
        static bool isChar(const std::string& literal);
        static bool isInt(const std::string& literal);
        static bool isFloat(const std::string& literal);
        static bool isDouble(const std::string& literal);
        static bool isPseudoLiteral(const std::string& literal);

        // Métodos para convertir según el tipo detectado
        static void convertFromChar(char c);
        static void convertFromInt(int i);
        static void convertFromFloat(float f);
        static void convertFromDouble(double d);
        static void convertFromPseudoLiteral(const std::string& literal);

    public:
        // Método estático para convertir
        static void convert(const std::string& literal);
};

#endif