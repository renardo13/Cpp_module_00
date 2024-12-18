#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected :
        std::string type;

    public :
        Animal(void);
        virtual ~Animal(void);
        Animal(std::string type);
        Animal(Animal const &cpy);
        Animal &operator=(Animal const &other);
        std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif