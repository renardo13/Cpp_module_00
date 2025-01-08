#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>

class PmergeMe
{
private:
    std::vector<int> _array_lst;
    // std::array<int, 30000> _array_arr;
    int _pairs;

public:
    PmergeMe() {};
    ~PmergeMe() {};
    PmergeMe(PmergeMe const &cpy);
    PmergeMe const &operator=(PmergeMe const &other);

    PmergeMe(std::vector<int> array) : _array_lst(array), _pairs(1) {}
    // PmergeMe(std::array<int, 30000> array) : array_arr(array) , _recursion_level(0){}
    std::vector<int> ford_johnson(PmergeMe &stack);

    // operator
    std::vector<int> &operator[](unsigned int i);

    // functions
    template <typename T>
    void print_lst(std::vector<T> lst);
    void swap(int *nb1, int *nb2);
    void swap_range(int start, int end, int start_swap, int end_swap);
    void add_pend(int pairs, std::vector<int>& pend, int odd_size, std::vector<int> main );
};
