#ifndef SHRUUBBERYCREATIONFORM_HPP
#define SHRUUBBERYCREATIONFORM_HPP
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
    private:
        std::string target;
    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &scf);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &scf);
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

};

#endif