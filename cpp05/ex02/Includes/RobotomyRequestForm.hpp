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
        RobotomyRequestForm(RobotomyRequestForm const &cpy);
        RobotomyRequestForm const& operator=(RobotomyRequestForm const& other);

        RobotomyRequestForm(std::string const target, int grade);
        void execute(Bureaucrat const& executor) const;

};
