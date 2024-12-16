#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private :
        Brain brain;

    public :
        Cat(void);
        ~Cat(void);
        Cat(Cat const &cpy);
        Cat &operator=(Cat const &other);
        void makeSound(void) const;
        std::string getType(void) const;
};

#endif