#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Bureaucrat1", 2);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl; 

        b1.incrementGrade(); // debería lanzar excepción
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
std::cout << "----------------------------------------------------------" << std::endl;
    try {
        Bureaucrat b2("Bureaucrat2", 150);
        std::cout << b2 << std::endl;

        b2.decrementGrade(); // debería lanzar excepción
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}