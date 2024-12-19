#include "../Includes/Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("Gilbert", 200);
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b1("Gilbert", -1);   
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Bureaucrat b2("Gilbert", 12);  
}
