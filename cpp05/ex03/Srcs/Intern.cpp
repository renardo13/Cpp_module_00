#include "../Includes/Intern.hpp"
#include "../Includes/AForm.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &cpy)
{
    if(this != &cpy)
        *this = cpy;
}

Intern const& Intern::operator=(Intern const &other)
{
    (void)other;
    return(*this);
}

AForm *Intern::newShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target, 20));
}

AForm *Intern::newRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target, 20));
}

AForm *Intern::newPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target, 20));
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {"shrubbery request", "robotomy request", "presidential request"};
	AForm *(*tab[])(std::string target) = {&newShrubberyCreationForm, &newRobotomyRequestForm, &newPresidentialPardonForm};
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == form)
		{
			std::cout << "Intern creates " << form << " for " << target << std::endl;
			return (tab[i](target));
		}
	}
    std::cout << "* This specific kind of form doesn't exist ! " << std::endl;
    return(NULL);
}