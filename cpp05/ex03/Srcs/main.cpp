#include "../Includes/Bureaucrat.hpp"
#include "../Includes/Intern.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/AForm.hpp"

int main(void)
{
    Intern someRandomIntern;
    AForm *rrf;

    std::cout << std::string(40, '*') << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        // std::cout << *rrf;
        delete rrf;
    }

    std::cout << std::string(40, '*') << std::endl;
    rrf = someRandomIntern.makeForm("Unknown", "Bender");
    if (rrf)
    {
        // std::cout << *rrf;
        delete rrf;
    }
    std::cout << std::string(40, '*') << std::endl;
    rrf = someRandomIntern.makeForm("presidential request", "Bender");
    if (rrf)
    {
        // std::cout << *rrf;
        delete rrf;
    }
    std::cout << std::string(40, '*') << std::endl;
    rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
    if (rrf)
    {
        // std::cout << *rrf;
        delete rrf;
    }
    return (0);
}
