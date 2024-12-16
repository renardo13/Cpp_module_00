#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private : 
        std::string _ideas[100];

    public :
        Brain(void);
        ~Brain(void);
        Brain(std::string ideas[100]);
        Brain(Brain const &cpy);
        Brain &operator=(Brain const &other);
};

#endif