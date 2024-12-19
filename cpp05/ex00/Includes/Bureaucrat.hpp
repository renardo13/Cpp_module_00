#pragma once

#include <iostream>
#include <exception>

class Bureaucrat
{
    private :
        std::string _name;
        int _grade;
    public:
        Bureaucrat();
        ~Bureaucrat();
        Bureaucrat(Bureaucrat const &cpy);
        Bureaucrat const& operator=(Bureaucrat const &other);

        Bureaucrat(std::string name, int grade);

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
        
        std::string getName();
        int getGrade();

};