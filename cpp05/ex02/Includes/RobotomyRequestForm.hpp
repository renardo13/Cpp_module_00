#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        //canonical class
        RobotomyRequestForm();
        ~RobotomyRequestForm();
        RobotomyRequestForm(AForm const &cpy);
        RobotomyRequestForm const& operator=(RobotomyRequestForm const& other);

        RobotomyRequestForm(std::string const target, int grade);
};

std::ostream& operator<<(std::ostream& buffer, RobotomyRequestForm const& src);