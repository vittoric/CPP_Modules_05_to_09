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
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}