#include "../Includes/Bureaucrat.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/AForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat Gilbert("Gilbert", 25);
        AForm *aform = new PresidentialPardonForm();
        aform->beSigned(Gilbert);
        aform->execute(Gilbert);
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat Gilbert("Gilbert", 19);
        AForm *treeForm = new ShrubberyCreationForm("TreeForm", 20);
        treeForm->beSigned(Gilbert);
        treeForm->execute(Gilbert);
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << std::endl;
    }
    return (0);
}
