#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
    private :
        std::string const _name;
        int _grade;

    public:
        //canonical class form
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &cpy);
        Bureaucrat const& operator=(Bureaucrat const &other);
        Bureaucrat(std::string name, int grade);

        //operators
        void operator++(int);
        void operator--(int);

        //exceptions
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
             public:
                virtual const char *what() const throw();
        };
        
        //getter
        std::string const getName() const;
        int getGrade() const;

};
std::ostream& operator<<(std::ostream& buffer, Bureaucrat const& src);
