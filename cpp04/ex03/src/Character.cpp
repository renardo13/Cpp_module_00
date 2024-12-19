#include "../includes/Character.hpp"

Character::~Character(void)
{
    std::cout << "Character destructeur is called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if(this->_materia[i])
            delete this->_materia[i];
    }
}

Character::Character(void) : ICharacter(), _name("Robert")
{
    std::cout << "Character constructeur is called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

Character::Character(Character const &cpy)
{
    std::cout << "Character copy constructeur is called" << std::endl;
    *this = cpy;
}

Character::Character(std::string const name) : ICharacter(), _name(name)
{
    std::cout << "Character constructor with param is called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

Character &Character::operator=(Character const &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete this->_materia[i];
            this->_materia[i] = NULL;
            if (other._materia[i])
                this->_materia[i] = other._materia[i]->clone();
        }
    }
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria *m)
{
    int i = 0;

    while (m && i < 4)
    {
        if (!this->_materia[i])
        {
            this->_materia[i] = m->clone();
            i = -1;
            break;
        }
        i++;
    }
    if (i == 4)
        std::cout << "Inventory is full" << std::endl;
    else if (i == 0)
        std::cout << "Impossible to add this specific kind of materia" << std::endl;
    else
        std::cout << "Materia was added successfully" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (!this->_materia[idx])
            std::cout << "There is no materia here" << std::endl;
        else
        {
            std::cout << "Materia was remove successfully" << std::endl;
            delete this->_materia[idx];
            this->_materia[idx] = NULL;
        }
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4)
    {
        if (!this->_materia[idx])
            std::cout << "There is no materia here" << std::endl;
        else
        {
            std::cout << "Materia is used successfully" << std::endl;
            this->_materia[idx]->use(target);
        }
    }
}
