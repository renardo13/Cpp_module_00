#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include <fstream> 

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        //canonical class
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(AForm const &cpy);
        ShrubberyCreationForm const& operator=(ShrubberyCreationForm const& other);

        ShrubberyCreationForm(std::string const target, int grade);
};

std::ostream& operator<<(std::ostream& buffer, ShrubberyCreationForm const& src);