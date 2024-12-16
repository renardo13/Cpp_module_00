#include "../includes/Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain constructor is called" << std::endl;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor is called" << std::endl;
}

Brain::Brain(Brain const &cpy)
{
    std::cout << "Brain copy constructor with type is called" << std::endl;
    *this = cpy;
}

Brain& Brain::operator=(Brain const &other)
{
    return(*this);
}

Brain::Brain(std::string ideas[100])
{
    this->_ideas = ideas;
}

