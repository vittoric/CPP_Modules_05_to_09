#include "Bureaucrat.hpp"
#include "AForm.hpp"

//validacion de grado
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    else if (grade > 150) {
        throw GradeTooLowException();
    }
    this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}

//geters
std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

//modificadores 
void Bureaucrat::incrementGrade(){
    if (this->grade - 1 < 1){
        throw GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade(){
    if (this->grade + 1 > 150){
        throw GradeTooLowException();
    }
    this->grade++;
}

void Bureaucrat::signForm(AForm &f) {
    try {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch(std::exception &e) {
        std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form){
    try{
        form.execute(*this);
        std::cout << name << " executes " << form.getName() << std::endl;
    }
    catch(std::exception &e){
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}