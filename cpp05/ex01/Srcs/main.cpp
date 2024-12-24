#include "../Includes/Bureaucrat.hpp"
#include "../Includes/Form.hpp"

int main(void)
{
    Form form;

    Bureaucrat b2("Gilbert", 150);
    std::cout << std::string(40, '_') << std::endl;
    std::cout << b2 << std::endl;
    std::cout << form << std::endl;
    std::cout << std::string(40, '*') << std::endl;
    try
    {
        b2--;
        form.beSigned(b2); // to sign the form is the grade "isSigned" is enough and change the bool to 1.
        b2.signForm(form); // if the bool is 1, we just print a message to inform that the form has been sign.
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::string(40, '_') << std::endl;
    std::cout << b2 << std::endl;
    std::cout << form << std::endl;
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

}



