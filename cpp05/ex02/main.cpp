#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 50);
        Bureaucrat charlie("Charlie", 150);

        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Bob the Criminal");

        std::cout << "\n--- Initial Form Status ---\n";
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        std::cout << "\n--- Signing Forms ---\n";
      
        alice.signForm(robotomy);
        alice.signForm(pardon);
        std::cout << std::endl;
        bob.signForm(robotomy);
        bob.signForm(pardon);
        std::cout << std::endl;
        charlie.signForm(shrubbery);
        charlie.signForm(robotomy);
        charlie.signForm(pardon);

        std::cout << "\n--- Executing Forms ---\n";
        bob.executeForm(shrubbery);
        std::cout << std::endl;
        alice.executeForm(robotomy);
        std::cout << std::endl;
        alice.executeForm(pardon);

        std::cout << "\n--- Trying to execute without signing ---\n";
        bob.executeForm(shrubbery); // No debería ejecutarse


        std::cout << "\n--- Test de Grados Límite ---\n";
        // Test para ShrubberyCreationForm (145/137)
        Bureaucrat test1("Test1", 146); // Debería fallar al firmar
        Bureaucrat test2("Test2", 138); // Debería fallar al ejecutar
        test1.signForm(shrubbery);
        test2.executeForm(shrubbery);

        // Test para RobotomyRequestForm (72/45)
        Bureaucrat test3("Test3", 73);  // Debería fallar al firmar
        Bureaucrat test4("Test4", 46);  // Debería fallar al ejecutar
        test3.signForm(robotomy);
        test4.executeForm(robotomy);

        // Test para PresidentialPardonForm (25/5)
        Bureaucrat test5("Test5", 26);  // Debería fallar al firmar
        Bureaucrat test6("Test6", 6);   // Debería fallar al ejecutar
        test5.signForm(pardon);
        test6.executeForm(pardon);

        std::cout << "\n--- Test de Múltiples Ejecuciones ---\n";
        // Ejecutar el mismo formulario varias veces (especialmente importante para RobotomyRequestForm)
        alice.executeForm(robotomy);
        alice.executeForm(robotomy);
        alice.executeForm(robotomy);

        std::cout << "\n--- Test de Verificación de Archivos ---\n";
        // Verificar la creación del archivo Shrubbery
        ShrubberyCreationForm garden("test_garden");
        alice.signForm(garden);
        alice.executeForm(garden);
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}