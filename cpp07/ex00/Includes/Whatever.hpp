#pragma once 

#include <iostream>

template <typename T> // You have to reencapsulate the typename
void swap(T const& a, T const& b)
{
    T tmp;

    tmp = b;
    b = a;
    a = tmp;
}   

template <typename T>
T const& max(T const& a, T const& b)
{
    return((a >= b) ? : a, b);
}

template <typename T>
T const& min(T const& a, T const& b)
{
   return((a <= b) ? : a, b);
}

