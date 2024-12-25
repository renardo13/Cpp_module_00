#include "../Includes/Base.hpp"

Base * generate(void)
{
    return(new B());
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type is A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "Type is B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "Type is C" << std::endl;
}


void identify(Base& p)
{
    Base tmp;
	
    try 
    {
        tmp = dynamic_cast<A &>(p);
    } 
    catch (std::exception &e) {}
    try 
    {
        tmp = dynamic_cast<B &>(p);
        std::cout << "Class B" << std::endl;
    } 
    catch (std::exception &e) {}
    try 
    {
        tmp = dynamic_cast<C &>(p);
        std::cout << "Class C" << std::endl;
    } catch (std::exception &e) {}
}
