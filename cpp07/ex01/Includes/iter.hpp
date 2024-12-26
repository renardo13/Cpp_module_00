#pragma once

#include <iostream>

template <typename T, typename funct>
void iter(T& array, size_t size, funct func)
{
    for(size_t i = 0; i < size; i++)
        func(array[i]);
}
