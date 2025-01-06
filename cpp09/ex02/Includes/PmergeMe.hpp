#pragma once

#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <cstdlib>

class PmergeMe
{
    private: 
        std::list<int> _array_lst;
        // std::array<int, 30000> _array_arr;
        int _recursion_level;

    public:
        PmergeMe() {};
        ~PmergeMe() {};
        PmergeMe(PmergeMe const& cpy) ;
        PmergeMe const& operator=(PmergeMe const& other);

        PmergeMe(std::list<int> array) : _array_lst(array), _recursion_level(1) {}
        // PmergeMe(std::array<int, 30000> array) : array_arr(array) , _recursion_level(0){}
        std::list<int> ford_johnson(std::list<int>& array);

};
