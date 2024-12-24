#include "../Includes/Bureaucrat.hpp"
#include "../Includes/PresidentialPardonForm.hpp"
#include "../Includes/ShrubberyCreationForm.hpp"
#include "../Includes/RobotomyRequestForm.hpp"
#include "../Includes/AForm.hpp"

int main(void)
{ 
    Bureaucrat Gilbert("Gilbert", 5);
    AForm *aform = new PresidentialPardonForm();
    try
    {
        aform->beSigned(Gilbert);
        aform->execute(Gilbert);
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << std::endl;
    }
    // increment the grade so the grade becames too low
    Gilbert++;
    delete aform;

    std::cout << std::string(40, '_') << std::endl;
    aform = new ShrubberyCreationForm();
    try
    {
        aform->beSigned(Gilbert);
        aform->execute(Gilbert);
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << std::endl;
    }
    delete aform;
    
    std::cout << std::string(40, '_') << std::endl;
    aform = new RobotomyRequestForm();
    Bureaucrat Jerome("Jerome", 44);
    try
    {
        // aform->beSigned(Jerome);
        aform->execute(Jerome);
    }
    catch(const std::exception& e)
    {
       std::cerr << e.what() << std::endl;
    }
    delete aform;
    return (0);
}
