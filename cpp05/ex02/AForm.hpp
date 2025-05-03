#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        //excepciones
        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw(){
                    return "Grade is too high!";
                };
        };

        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw(){
                    return "Grade is too low!";
                }
        };

        class FormNotSignedException : public std::exception{
            public:
                const char* what() const throw(){
                    return "Form is not signed!";
                }
        };

        AForm(std::string name, int gradeToSign, int gradeToExecute);
        virtual ~AForm();

        //geters
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        //metodos
        void beSigned(const Bureaucrat &b);
        virtual void execute(Bureaucrat const & executor) const = 0; //metodo abrstacto
};

    std::ostream& operator<<(std::ostream& os, const AForm& f);

    #endif