#ifndef AMATERIA_HPP

#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;

    public : 
    
        AMateria();
        virtual ~AMateria();
        AMateria(std::string const type);
        AMateria(AMateria const &cpy);
        AMateria& operator=(AMateria const &other);

        std::string const &getType() const; // Returns the materia type
        void setType(std::string const &type); // Returns the materia type
        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif