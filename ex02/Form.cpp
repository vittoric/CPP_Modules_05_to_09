#include "Form.hpp"

//constructor con validacion de grado
Form::Form(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        if (gradeToSign < 1 || gradeToExecute < 1){
            throw GradeTooHighException();
        }
        if (gradeToSign > 150 || gradeToExecute > 150){
            throw GradeTooLowException();
        }
    }

Form::~Form(){}

//geters
std::string Form::getName() const{
    return name;
}  
bool Form::getIsSigned() const{
    return isSigned;
}  

int Form::getGradeToSign() const{
    return gradeToSign;
}

int Form::getGradeToExecute() const{
    return gradeToExecute;
}

//metodos
void Form::beSigned(const Bureaucrat &b){
    if (b.getGrade() > gradeToSign){
        throw GradeTooLowException();
    }
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f){
    os << "Form: " << f.getName() 
       << " | Signed: " << (f.getIsSigned() ? "Yes" : "No") 
       << " | Grade required to sign: " << f.getGradeToSign()
       << " | Grade required to execute: " << f.getGradeToExecute();
    return os;
}