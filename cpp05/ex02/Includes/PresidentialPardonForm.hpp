#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        //canonical class
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &cpy);
        PresidentialPardonForm const& operator=(PresidentialPardonForm const& other);

        PresidentialPardonForm(std::string const target, int grade);
        void execute(Bureaucrat const& executor) const;
};
