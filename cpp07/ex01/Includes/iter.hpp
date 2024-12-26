#pragma once

#include <iostream>

template <typename T>
void iter(T& array, T size, void funct(T&))
{
    for(int i = 0; i <  size; i++)
    {
        funct(array[i]);
    }
}