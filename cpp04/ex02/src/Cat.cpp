#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

Cat::~Cat()
{
    std::cout << "Cat destructor is called" << std::endl;
    delete this->_brain;
}

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat constructor with type is called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(Cat const &cpy) : Animal("Cat")
{
    std::cout << "Cat copy constructor with type is called" << std::endl;
    *this = cpy;
}

// Deep copy with new Brain
Cat &Cat::operator=(Cat const &other)
{
    if (this != &other)
    {
        this->type = other.type;
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Miaouuu je suis un chat" << std::endl;
}

Brain* Cat::getBrain(void) const
{
    return(this->_brain);
}
