#include "../includes/MateriaSource.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if(this->_materia[i])
            delete this->_materia[i];
    }
}

MateriaSource::MateriaSource(void) : IMateriaSource()
{
    std::cout << "MateriaSource default constructor is called" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &cpy)
{
    std::cout << "MateriaSource copy constructeur is called" << std::endl;
    *this = cpy;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{   
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            delete this->_materia[i];
            this->_materia[i] = NULL;
            if(other._materia[i])
                this->_materia[i] = other._materia[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    int i = 0;

    while (m && i < 4)
    {
        if (!this->_materia[i])
        {
            this->_materia[i] = m;
            break;
        }
        i++;
    }
    if (i == 4)
        std::cout << "Inventory is full" << std::endl;
    else
        std::cout << "New materia is now in the inventory, congratulations !" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
		{
			return (this->_materia[i]->clone());
		}
	}
    return NULL;
}
