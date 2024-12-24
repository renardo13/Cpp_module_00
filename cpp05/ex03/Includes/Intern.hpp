#pragma once

#include <iostream>
#include "AForm.hpp"

class Intern
{
    private:
		static AForm*	newShrubberyCreationForm(std::string target);
		static AForm*	newRobotomyRequestForm(std::string target);
		static AForm*	newPresidentialPardonForm(std::string target);

    public:
        Intern();
        ~Intern();
        Intern(Intern const& cpy);
        Intern const& operator=(Intern const& other);
        AForm* makeForm(std::string name, std::string target);
};