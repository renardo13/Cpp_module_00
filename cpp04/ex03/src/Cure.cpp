#include "../includes/Cure.hpp"

Cure::~Cure(void)
{
    std::cout << "Cure destructeur is called" << std::endl;
}

Cure::Cure(void) : AMateria()
{
    std::cout << "Cure constructeur is called" << std::endl;
    this->_type = "cure";
}

Cure::Cure(Cure const &cpy)
{
    std::cout << "Cure copy constructeur is called" << std::endl;
    *this = cpy;
}

Cure& Cure::operator=(Cure const &other)
{
    if(this != &other)
        this->_type = other._type;
    return(*this);
}

//Cure is a type of AMateria so it is possible to copy it, it is polymorphism
AMateria* Cure::clone() const
{
    AMateria *tmp = new Cure();
    tmp->setType("cure");
    return(tmp);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wound  *" << std::endl;
}
