#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private :
        Brain *_brain;

    public :
        Dog(void);
        ~Dog(void);
        Dog(Dog const &cpy);
        Dog &operator=(Dog const &other);
        void makeSound(void) const;
};

#endif
