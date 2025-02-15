#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &i) {
    *this = i;
}

Intern &Intern::operator=(const Intern &i) {
    (void)i;
    return *this;
}

// Métodos estáticos para crear formularios
AForm *Intern::createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardon(std::string target) {
    return new PresidentialPardonForm(target);
}


AForm *Intern::makeForm(std::string formName, std::string target){
    std::string formNames[3] = {
        "robotomy request", 
        "presidential pardon", 
        "shrubbery creation"
        };
    
     AForm *(*formCreators[3])(std::string) = {
        createShrubbery,
        createRobotomy,
        createPresidentialPardon
    };

    for (int i = 0; i < 3; i++){
        if (formName == formNames[i]){
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Intern couldn't create " << formName << std::endl;
    return NULL;
}