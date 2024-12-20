#include "../Includes/Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("Gilbert", 200);
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b1("Gilbert", 1000);   
    }
    catch(std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Bureaucrat b2("Gilbert", 12);
}

