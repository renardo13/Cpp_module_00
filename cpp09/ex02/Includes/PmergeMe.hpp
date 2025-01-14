#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>

class PmergeMe
{
private:
    std::vector<int> vec;
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<int> odd;
    std::vector<int> tmp;
    // std::array<int, 30000> _array_arr;
    int _pairs;

public:
    PmergeMe() {};
    ~PmergeMe() {};
    PmergeMe(PmergeMe const &cpy);
    PmergeMe const &operator=(PmergeMe const &other);

    PmergeMe(std::vector<int> array) : vec(array), _pairs(1) {}

    //Ford Johnson with std::vector
    std::vector<int> ford_johnson(PmergeMe &stack);
    // functions
    template <typename T>
    void print_lst(std::vector<T> lst);
    void swap(int *nb1, int *nb2);
    void swap_range(int start, int end, int start_swap, int end_swap);

    long  jacobsthal(long n);
    void binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> &nb, int idx_nb, int pair);


    //Ford Johnson with std::vector
};
