#include "Ice.hpp"

Ice::~Ice(void)
{
    std::cout << "Ice destructeur is called" << std::endl;
}

Ice::Ice(void) : AMateria()
{
    std::cout << "Ice constructeur is called" << std::endl;
    this->_type = "ice";
}

Ice::Ice(Ice const &cpy)
{
    std::cout << "Ice copy constructeur is called" << std::endl;
    *this = cpy;
}

Ice& Ice::operator=(Ice const &other)
{
    if(this != &other)
    {
        this->_type = other._type;
    }
    return(*this);
}

//Cure is a type of AMateria so it is possible to copy it, it is polymorphism
AMateria* Ice::clone() const
{
    AMateria *tmp = new Ice();
    tmp->setType("ice");
    return(tmp);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}


    
