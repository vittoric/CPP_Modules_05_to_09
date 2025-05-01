#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "Test 1: Operaciones normales\n" << std::endl;
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
    std::cout << "\nTest 2 de creación de Form con grados inválidos" << std::endl;
    try {
        Form invalidForm1("Invalid1", 0, 50);    // Muy alto
    } catch (std::exception &e) {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("Invalid2", 50, 151);  // Muy bajo
    } catch (std::exception &e) {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }

    std::cout << "\nTest 3 de firma con burócrata de bajo rangos" << std::endl;
    try {
        Form f3("Simple Form", 140, 140);
        Bureaucrat b2("B2", 150);
        b2.signForm(f3);  // Morty (grado 150) intentando firmar
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 4 de firma múltiple del mismo formulario" << std::endl;
    try {
        Form f4("Multiple Sign", 5, 5);
        Bureaucrat b1("Rick", 2);
        Bureaucrat b2("Morty", 150);
        b1.signForm(f4);  // Primera firma
        b1.signForm(f4);  // Intento de segunda firma
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\nTest 5 de estado inicial del formulario" << std::endl;
    try {
        Form f5("New Form", 50, 50);
        std::cout << "Initial signed status: " << (f5.getIsSigned() ? "Yes" : "No") << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}