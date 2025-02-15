#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
    private:
        std::string target;
    public:
        RobotomyRequestForm(std::string target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &rrf);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rrf);
        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

};

#endif