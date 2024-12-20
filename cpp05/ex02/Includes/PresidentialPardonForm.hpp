#pragma once

#include <iostream>
#include <exception>
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
};

std::ostream& operator<<(std::ostream& buffer, PresidentialPardonForm const& src);