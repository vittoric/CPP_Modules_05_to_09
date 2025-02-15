#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Rick", 2);
        Bureaucrat b2("Morty", 150);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;

        Form f1("Destroy Planet E458", 5, 10);
        Form f2("LAse Gun", 1, 2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        // Intentar firmar con Bureaucrat1 (debería firmar f1, pero no f2)
        b1.signForm(f1);
        b1.signForm(f2);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}