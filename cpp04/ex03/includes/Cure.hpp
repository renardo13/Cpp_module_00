#ifndef CURE_HPP

#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : virtual public AMateria
{
    public :
        Cure();
        ~Cure();
        Cure(Cure const &cpy);
        Cure& operator=(Cure const &other);

        // Inherited methods from AMateria
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif