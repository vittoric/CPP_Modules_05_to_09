#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) :
AForm(rrf.getName(), 72, 45) {
    if (this != &rrf){
        *this = rrf;
    }
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf){
    if (this != &rrf){
        this->target = rrf.getTraget();
    }
    return *this;
}

std::string RobotomyRequestForm::getTraget() const{
    return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
   if (!this->getIsSigned()) {
        throw FormNotSignedException();
    }

    // Verificar si el Bureaucrat tiene el grado suficiente
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::cout << "* Drilling noises *" << std::endl;
    std::cout << this->getTraget() << " has been robotomized successfully 50% of the time." << std::endl;
}