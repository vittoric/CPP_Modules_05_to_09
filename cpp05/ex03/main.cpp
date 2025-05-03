// main.cpp
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>  // Para leer el archivo

int main() {
    try {
        std::cout << "\n🔹🔹🔹 Creating Forms with Intern 🔹🔹🔹\n" << std::endl;

        Intern intern;
        AForm *form1 = intern.makeForm("robotomy request", "Bender");
        AForm *form2 = intern.makeForm("shrubbery creation", "Home");
        AForm *form3 = intern.makeForm("presidential pardon", "Alice");
        AForm *invalidForm = intern.makeForm("random form", "Unknown");

        std::cout << "\n📝 Created Forms:\n";
        if (form1)
            std::cout << "✅ Form created: " << form1->getName() << " (Target: " << "Bender" << ")\n";
        if (form2)
            std::cout << "✅ Form created: " << form2->getName() << " (Target: " << "Home" << ")\n";
        if (form3)
            std::cout << "✅ Form created: " << form3->getName() << " (Target: " << "Alice" << ")\n";

        std::cout << "\n🔴 Random Form should be NULL: " << (invalidForm == NULL ? "✅ PASS" : "❌ FAIL") << std::endl;

        std::cout << "\n🔹🔹🔹 Testing Bureaucrat Signing & Execution 🔹🔹🔹\n" << std::endl;

        Bureaucrat alice("Alice", 1);  // Puede firmar y ejecutar todo
        Bureaucrat bob("Bob", 50);     // Puede firmar y ejecutar algunos formularios
        Bureaucrat charlie("Charlie", 150); // No puede firmar ni ejecutar nada alto

        std::cout << "\n👉 Signing Forms:\n";
        alice.signForm(*form2);
        bob.signForm(*form1);
        charlie.signForm(*form3); // Charlie no debería poder firmar

        std::cout << "\n👉 Trying to Execute Forms:\n";
        bob.executeForm(*form2); // Bob debería poder ejecutar Shrubbery
        alice.executeForm(*form1); // Alice puede ejecutar Robotomy
        alice.executeForm(*form3); // Alice puede ejecutar Pardon

        std::cout << "\n👉 Trying to Execute Without Signing:\n";
        charlie.executeForm(*form2); // Charlie no debería poder ejecutarlo

        std::cout << "\n🔹🔹🔹 Testing Grade Limits 🔹🔹🔹\n" << std::endl;
        
        // Test para ShrubberyCreationForm (145/137)
        Bureaucrat test1("Test1", 146); // Debería fallar al firmar
        Bureaucrat test2("Test2", 138); // Debería fallar al ejecutar
        test1.signForm(*form2);
        test2.executeForm(*form2);

        // Test para RobotomyRequestForm (72/45)
        Bureaucrat test3("Test3", 73);  // Debería fallar al firmar
        Bureaucrat test4("Test4", 46);  // Debería fallar al ejecutar
        test3.signForm(*form1);
        test4.executeForm(*form1);

        // Test para PresidentialPardonForm (25/5)
        Bureaucrat test5("Test5", 26);  // Debería fallar al firmar
        Bureaucrat test6("Test6", 6);   // Debería fallar al ejecutar
        test5.signForm(*form3);
        test6.executeForm(*form3);

        std::cout << "\n🔹🔹🔹 Testing Multiple Robotomy Executions 🔹🔹🔹\n" << std::endl;
        alice.signForm(*form1);
        for(int i = 0; i < 5; i++) {
            std::cout << "Attempt " << i + 1 << ": ";
            alice.executeForm(*form1);
        }

        // Crear un formulario Shrubbery para Bender y ejecutarlo
        AForm *benderForm = intern.makeForm("shrubbery creation", "Bender");
        if (benderForm) {
            std::cout << "\n🔹🔹🔹 Creating Bender's Shrubbery 🔹🔹🔹\n" << std::endl;
            alice.signForm(*benderForm);
            alice.executeForm(*benderForm);
            
            // Mostrar el contenido del archivo Bender_shrubbery
            std::cout << "\n🔹🔹🔹 Contenido del archivo Bender_shrubbery 🔹🔹🔹\n" << std::endl;
            std::ifstream file("Bender_shrubbery");
            if (file.is_open()) {
                std::string line;
                while (getline(file, line)) {
                    std::cout << line << std::endl;
                }
                file.close();
            } else {
                std::cerr << "❌ No se pudo abrir el archivo Bender_shrubbery" << std::endl;
            }
            
            delete benderForm;
        }

        // Liberar memoria
        delete form1;
        delete form2;
        delete form3;
    }
    catch (std::exception &e) {
        std::cerr << "❌ Exception: " << e.what() << std::endl;
    }

    return 0;
}