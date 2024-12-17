#include "../includes/Character.hpp"

Character::~Character(void)
{
    std::cout << "Character destructeur is called" << std::endl;
}

Character::Character(void)
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

Character::Character(std::string const name) : _name(name)
{
    std::cout << "Character constructor with param is called" << std::endl;
}

Character &Character::operator=(Character const &other)
{
    (void)other;
    return (*this);
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria *m)
{
    int i = 0;

    while (i < 4)
    {
        if (!this->_materia[i])
        {
            this->_materia[i] = m;
            break;
        }
        i++;
    }
    if (i == 4)
    {
        std::cout << "Materia is full" << std::endl;
    }
    else
    {
        std::cout << "Materia was added succesfuly" << std::endl;
    }
}

void Character::unequip(int idx)
{
    if (!_materia[idx])
        std::cout << "Materia not exists" << std::endl;
    this->_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{

    if (this->_materia[idx])
        this->_materia[idx]->use(target);
}