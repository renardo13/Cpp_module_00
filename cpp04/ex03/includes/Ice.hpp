#ifndef ICE_HPP

#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : virtual public AMateria
{
    public :
        Ice();
        ~Ice();
        Ice(Ice const &cpy);
        Ice& operator=(Ice const &other);

        // Inherited methods from AMateria
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif