#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat(void);
        ~WrongCat(void);
        WrongCat(WrongCat const &cpy);
        WrongCat &operator=(WrongCat const &other);
        void makeSound(void) const;
        std::string getType(void);
};

#endif