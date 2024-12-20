#include "../Includes/Bureaucrat.hpp"
#include "../Includes/Form.hpp"

int main(void)
{
    Form form;

    try
    {
        Bureaucrat b("Gilbert", 200);
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::string(40, '*') << std::endl;
    try
    {
        Bureaucrat b1("Gilbert", -1);   
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::string(40, '*') << std::endl;
    Bureaucrat b2("Gilbert", 150);
    try
    {
        b2--;
        b2.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << b2 << std::endl;
    std::cout << form << std::endl;
    std::cout << std::string(40, '*') << std::endl;
    try
    {
        b2++;
        form.beSigned(b2);
        b2.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::string(40, '*') << std::endl;
    std::cout << b2 << std::endl;
    std::cout << form << std::endl;
}



