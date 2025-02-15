#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm;

class Intern{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &i);
        Intern &operator=(const Intern &i);
        AForm *makeForm(std::string formName, std::string target);
    private:
        static AForm *createShrubbery(std::string target);
        static AForm *createRobotomy(std::string target);
        static AForm *createPresidentialPardon(std::string target);

};

#endif