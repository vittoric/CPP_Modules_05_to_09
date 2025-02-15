#include "Bureaucrat.hpp"

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


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}