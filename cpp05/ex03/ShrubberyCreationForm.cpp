#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) :
AForm(scf.getName(), 145, 137) {
    if (this != &scf){
        *this = scf;
    }
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf){
    if (this != &scf){
        this->target = scf.getTarget();
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const{
    return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned()) {
        throw FormNotSignedException();
    }
std::cout << "Shrubbery Form signed status: " << getIsSigned() << std::endl;
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }

    std::string myFile = this->getTarget() + "_shrubbery";
    std::ofstream file(myFile.c_str());

    if (!file.is_open()) {
        throw std::runtime_error("Error opening file");
    }

    file << "       ,@@@@@@@,\n                             " << std::endl;
    file << "  ,,,.   ,@@@@@@/@@,  .oo8888o.\n              " << std::endl;
    file << " ,&%&&%&&%,@@@@@/@@@@@@,8888\\88/8o\n          " << std::endl;
    file << ",%&\\%&&%&&%,@@\\@@/ /@@@88888\\88888'\n       " << std::endl;
    file << "%&&%&%&/%&&%@@\\ V /@@' `88\\8 `/88'\n         " << std::endl;
    file << "`&%\\ ` /%&'    |.|        \\ '|8'\n           " << std::endl;
    file << "    |o|        | |         | |\n               " << std::endl;
    file << "    |.|        | |         | |\n               " << std::endl;
    file << " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n" << std::endl;

    file.close();
}