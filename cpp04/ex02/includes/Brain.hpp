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
        Brain(Brain const &cpy);
        Brain &operator=(Brain const &other);

        std::string getIdeas(int index) const;
        void setIdeas(std::string &ideas, int index);
};

#endif