#ifndef MATERIASOURCE_HPP

#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class IMateriaSource;

class MateriaSource : public IMateriaSource
{
    private :
        AMateria *_materia[4];

    public:

        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource const& cpy);
        MateriaSource& operator=(MateriaSource const& other);
        
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif