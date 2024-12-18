#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected :
        std::string type;

    public :
        WrongAnimal(void);
        virtual ~WrongAnimal(void);
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const &cpy);
        WrongAnimal &operator=(WrongAnimal const &other);
        std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif