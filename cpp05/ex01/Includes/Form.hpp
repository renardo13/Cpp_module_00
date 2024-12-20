#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        int const _signedGrade;
        int const _requiredGrade;
        bool _isSigned;

    public:
        //canonical class form
        Form();
        ~Form();
        Form(std::string const name, int formBool, int requiredGrade, int signedGrade);
        Form(Form const &cpy);
        Form const& operator=(Form const& other);

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

        void beSigned(Bureaucrat &src);

        //getter
        std::string getName() const;
        int getIsSigned() const;
        int getRequiredGrade() const;
        int getSignedGrade() const;
};

std::ostream& operator<<(std::ostream& buffer, Form const& src);