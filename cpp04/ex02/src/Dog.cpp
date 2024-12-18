#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

Dog::~Dog()
{
    std::cout << "Dog destructor is called" << std::endl;
    delete this->_brain;
}

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog constructor with type is called" << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(Dog const &cpy) : Animal("Dog")
{
    *this = cpy;
}

// Deep copy with new Brain
Dog &Dog::operator=(Dog const &other)
{
    if (this != &other)
    {
        this->type = other.type;
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "Ouaf ouaf je suis un toutou" << std::endl;
}
