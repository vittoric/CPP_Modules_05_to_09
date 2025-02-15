#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf) :
AForm(ppf.getName(), 25, 5) {
    if (this != &ppf){
        *this = ppf;
    }
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf){
    if (this != &ppf){
        this->target = ppf.getTarget();
    }
    return *this;
}

std::string PresidentialPardonForm::getTarget() const{
    return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    // Verificar si el formulario está firmado antes de ejecutar
    if (!this->getIsSigned()) {
        throw FormNotSignedException();
    }

    // Verificar si el Bureaucrat tiene el grado suficiente
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}