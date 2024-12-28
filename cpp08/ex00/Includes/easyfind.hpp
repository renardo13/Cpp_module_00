#pragma once

#include <iostream>
#include <vector>

template<typename T>
int easyfind(std::vector<T> list, int nb)
{
    typename std::vector<T>::iterator it;

    for(it = list.begin(); it <= list.end(); it++)
    {
        if (nb == *it)
            return(nb);
    }
    std::cout << "Element not found in the list." << std::endl;
    return(-1);
};
