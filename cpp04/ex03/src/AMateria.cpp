#include "../includes/AMateria.hpp"

AMateria::~AMateria(void)
{
    std::cout << "AMateria destructeur is called" << std::endl;
}

AMateria::AMateria()
{
    std::cout << "AMateria default constructeur is called" << std::endl;
    this->_type = "AMateria";
}

AMateria::AMateria(AMateria const &cpy)
{
    std::cout << "AMateria copy constructeur is called" << std::endl;
    *this = cpy;
}

AMateria& AMateria::operator=(AMateria const &other)
{
    if(this != &other)
    {
        this->_type = other._type;
    }
    return(*this);
}

std::string const& AMateria::getType(void) const
{
    return(this->_type);
}

void AMateria::setType(std::string const &type)
{
    this->_type = type;
}

void AMateria::use(ICharacter& target)
{
    if (this->_type == "ice")
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	if (this->_type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    else 
        std::cout << target.getName() << "has no type Ice nor cure" << std::endl;
}