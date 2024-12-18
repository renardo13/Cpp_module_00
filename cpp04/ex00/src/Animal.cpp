#include "../includes/Animal.hpp"

Animal::Animal(void)
{
    std::cout << "Animal constructor is called" << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destructor is called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal constructor with type is called" << std::endl;
}

Animal::Animal(Animal const &cpy)
{
    std::cout << "Animal copy constructor with type is called" << std::endl;
    *this = cpy;
}

Animal& Animal::operator=(Animal const &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);
}

void Animal::makeSound(void) const
{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType(void) const
{
    return(this->type);
}
