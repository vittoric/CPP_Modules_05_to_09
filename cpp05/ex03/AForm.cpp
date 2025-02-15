#include "AForm.hpp"

//constructor con validacion de grado
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
        if (gradeToSign < 1 || gradeToExecute < 1){
            throw GradeTooHighException();
        }
        if (gradeToSign > 150 || gradeToExecute > 150){
            throw GradeTooLowException();
        }
    }

AForm::~AForm(){}

//geters
std::string AForm::getName() const{
    return name;
}  
bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const{
    return gradeToSign;
}

int AForm::getGradeToExecute() const{
    return gradeToExecute;
}

//metodos
void AForm::beSigned(const Bureaucrat &b){
    if (b.getGrade() > gradeToSign){
        throw GradeTooLowException();
    }
    isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& f){
    os << "AForm: " << f.getName() 
       << " | Signed: " << (f.getIsSigned() ? "Yes" : "No") 
       << " | Grade required to sign: " << f.getGradeToSign()
       << " | Grade required to execute: " << f.getGradeToExecute();
    return os;
}

