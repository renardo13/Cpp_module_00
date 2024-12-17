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
        std::cout << "Materia inside MateriaSource is full" << std::endl;
    }
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    if (type == "ice")
        return new Ice();  // Crée un objet de type Ice
    else if (type == "cure")
        return new Cure();  // Crée un objet de type Cure
    // Ajoutez d'autres types ici si nécessaire

    return NULL;  // Si le type est inconnu, retourner nullptr
}