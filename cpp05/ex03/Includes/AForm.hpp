#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        int const _signedGrade;
        int const _executeGrade;
        bool _isSigned;

    public:
        //canonical class AForm
        AForm();
        virtual ~AForm();
        AForm(std::string const name, int formBool, int signedGrade, int executeGrade);
        AForm(AForm const &cpy);
        AForm const& operator=(AForm const& other);

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
        class CannotExecuteForm : public std::exception
        {
             public:
                virtual const char *what() const throw();
        };
        class FormNotSigned : public std::exception
        {
             public:
                virtual const char *what() const throw();
        };
        void beSigned(Bureaucrat &src);
        virtual void execute(Bureaucrat const& executor) const = 0;

        //getter
        std::string getName() const;
        int getIsSigned() const;
        int getexecuteGrade() const;
        int getSignedGrade() const;
};

std::ostream& operator<<(std::ostream& buffer, AForm const& src);