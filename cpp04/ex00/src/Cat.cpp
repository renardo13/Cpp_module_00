#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

Cat::~Cat()
{
    std::cout << "Cat destructor is called" << std::endl;
}

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat constructor with type is called" << std::endl;
}

Cat::Cat(Cat const &cpy) : Animal("Cat")
{
    std::cout << "Cat copy constructor with type is called" << std::endl;
    *this = cpy;
}

Cat& Cat::operator=(Cat const &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Miaouuu je suis un chat" << std::endl;
}
