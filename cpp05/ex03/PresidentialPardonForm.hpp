#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
        std::string target;
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &ppf);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &ppf);
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

};

#endif