#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor is called" << std::endl;
}

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor with type is called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &cpy) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat copy constructor with type is called" << std::endl;
    *this = cpy;
}

WrongCat& WrongCat::operator=(WrongCat const &other)
{
    if (this != &other)
        this->type = other.type;
    return(*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "Miaouuu je suis un chat" << std::endl;
}
