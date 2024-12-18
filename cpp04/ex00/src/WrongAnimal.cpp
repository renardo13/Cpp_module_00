#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal constructor is called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal constructor with type is called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &cpy)
{
    std::cout << "WrongAnimal copy constructor with type is called" << std::endl;
    *this = cpy;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return(this->type);
}
