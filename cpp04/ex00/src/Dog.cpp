#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

Dog::~Dog()
{
    std::cout << "Dog destructor is called" << std::endl;
}

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog constructor with type is called" << std::endl;
}

Dog::Dog(Dog const &cpy) : Animal("Dog")
{
    *this = cpy;
}

Dog& Dog::operator=(Dog const &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Ouaf ouaf je suis un toutou" << std::endl;
}
