#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        int const _grade;
        int const _requiredGrade;
        bool _isSigned;

    public:
        //canonical class AForm
        AForm();
        ~AForm();
        AForm(std::string const name, int AFormBool, int requiredGrade, int grade);
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

        void beSigned(Bureaucrat &src);
        virtual void execute(Bureaucrat const& executor) const = 0;

        //getter
        std::string getName() const;
        int getIsSigned() const;
        int getRequiredGrade() const;
        int getSignedGrade() const;
};

std::ostream& operator<<(std::ostream& buffer, AForm const& src);