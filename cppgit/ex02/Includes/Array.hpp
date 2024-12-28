#pragma once

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T* _tab;
        unsigned int _n;

    public:
        Array();
        ~Array();
        Array(Array<T> const& cpy);
        Array<T> const& operator=(Array<T> const& other);

        T const& operator[](unsigned int i) const;
        T& operator[](unsigned int i);
        Array(unsigned int _nb);
        size_t size(void) const;

};

// This is not necessary to cast in <T> type in the name of the functions but in the parameters it is
template <typename T>
Array<T>::~Array()
{
    if (this->_tab)
        delete[] this->_tab;
}

template <typename T>
Array<T>::Array() : _n(0), _tab(NULL) {}

template <typename T>
Array<T>::Array(Array<T> const& cpy)
{
    if(this != &cpy)
        *this = cpy;
}

template <typename T>
Array<T> const& Array<T>::operator=(Array<T> const& other)
{
    if (this != &other && this->_tab)
	{
        delete[] this->_tab;
        this->_tab = new T[this->_n];
        this->_n = other._n;
        for (unsigned int i = 0; i < this->_n; i++)
            this->_tab[i] = other._tab[i];
    }
    return(*this);
}

template <typename T>
T const& Array<T>::operator[](unsigned int i) const
{
    if(i >= 0 && i < this->_n)
        return(this->_tab[i]);
    throw std::out_of_range("index it's out of bounds");
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if(i >= 0 && i < this->_n)
        return(this->_tab[i]);
    throw std::out_of_range("index it's out of bounds");
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->_tab = new T[n];
    if(!this->_tab)
        std::cout << "Allocation of the template tab failed" << std::endl;
    this->_n = n;
}

template <typename T>
size_t Array<T>::size(void) const
{
    return(this->_n);
}