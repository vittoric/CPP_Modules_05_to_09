#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form{
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

        Form(std::string name, int gradeToSign, int gradeToExecute);
        ~Form();

        //geters
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        //metodos
        void beSigned(const Bureaucrat &b);

        friend std::ostream& operator<<(std::ostream& os, const Form& f);

};

#endif