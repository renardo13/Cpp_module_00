#include "../Includes/Base.hpp"

Base * generate(void)
{
    srand(time(0));
	int	i = rand() % 3;
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
    return(new C());
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
        std::cout << "Class A" << std::endl;
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
