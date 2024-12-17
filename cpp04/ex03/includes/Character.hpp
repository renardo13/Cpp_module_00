#ifndef CHARACTER_HPP

#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter;

class Character : public ICharacter
{
    private :
        std::string const _name;
        AMateria *_materia[4];

    public:

        Character();
        ~Character();
        Character(Character const& cpy);
        Character(std::string const name);
        Character& operator=(Character const& cpy);

        std::string const& getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif