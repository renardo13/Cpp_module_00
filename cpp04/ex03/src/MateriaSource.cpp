#include "../includes/MateriaSource.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor is called" << std::endl;
}
MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor is called" << std::endl;
    for(int i = 0; i < 4; i++)
        this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &cpy)
{
    *this = cpy;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
    (void)other;
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
            i = -1;
            break;
        }
        i++;
    }
    if (i == 4)
        std::cout << "Materia inside MateriaSource is full" << std::endl;
    else if (i == 0)
        std::cout << "You tried to add an empty materia" << std::endl;
    else 
        std::cout << "Materia is successfully added" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    if (type == "ice")
        return new Ice();  // Crée un objet de type Ice
    else if (type == "cure")
        return new Cure();  // Crée un objet de type Cure
    else 
        std::cout << "Materia does not exists" << std::endl;

    return NULL;  // Si le type est inconnu, retourner nullptr
}