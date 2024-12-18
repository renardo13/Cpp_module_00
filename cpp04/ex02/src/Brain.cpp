#include "../includes/Brain.hpp"

Brain::~Brain(void)
{
    std::cout << "Brain destructor is called" << std::endl;
}

Brain::Brain(void)
{
    std::cout << "Brain constructor is called" << std::endl;
    for(int i = 0; i < 100; i++)
        this->_ideas[i] = "Je suis le cerveau d'un chat ou d'un chien";
}

Brain::Brain(Brain const &cpy)
{
    std::cout << "Brain copy constructor with type is called" << std::endl;
    *this = cpy;
}

Brain& Brain::operator=(Brain const &other)
{
    if(this != &other)
    {
        for(int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return(*this);
}

std::string Brain::getIdeas(int index) const
{
    if(index > 0 && index < 100)
        return(this->_ideas[index]);
    return(NULL);
}

void Brain::setIdeas(std::string &ideas, int index)
{
    this->_ideas[index] = ideas;
}




