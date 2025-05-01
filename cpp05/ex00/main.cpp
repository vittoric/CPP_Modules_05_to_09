#include "Bureaucrat.hpp"

int main() {
    std::cout << "Test 1: Incremento hasta límite superior" << std::endl;
    try {
        Bureaucrat b1("Bureaucrat 1", 2);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl; 
        b1.incrementGrade(); // debería lanzar excepción
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 2: Decremento en límite inferior" << std::endl;
    try {
        Bureaucrat b2("Bureaucrat 2", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade(); // debería lanzar excepción
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 3: Constructor con grado inválido" << std::endl;
    try {
        Bureaucrat b3("Bureaucrat 3", 151); // debería lanzar excepción
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("Bureaucrat 4", 0); // debería lanzar excepción
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 4: Operaciones normales" << std::endl;
    try {
        Bureaucrat b5("Bureaucrat 5", 75);
        std::cout << b5 << std::endl;
        b5.incrementGrade();
        std::cout << "After increment: " << b5 << std::endl;
        b5.decrementGrade();
        std::cout << "After decrement: " << b5 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}