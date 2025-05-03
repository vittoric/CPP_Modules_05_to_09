#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        //Exepciones personalizadas con metodos virtuales
        //que heredan de la clase exception
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

        //sobrecarga del operador <<
        
    };

    std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif