#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        //Exepciones personalizadas
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw(){
                    return "Grade is too high!";
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw(){
                    return "Grade is too low!";
                }
        };

        //constructor y destructor
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();

        //metodos de acceso
        std::string getName() const;
        int getGrade() const;

        //metodos de modificacion
        void incrementGrade();
        void decrementGrade();

        void signForm(Form &f);

        //sobrecarga del operador <<
        friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
};

#endif