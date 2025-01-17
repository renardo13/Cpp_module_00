#pragma once

#include <iostream>
#include <vector>
#include <deque>
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

    std::deque<int> deque_vec;
    std::deque<int> deque_main;
    std::deque<int> deque_pend;
    std::deque<int> deque_odd;
    std::deque<int> deque_tmp;
    int _pairs;

public:
    PmergeMe() {};
    ~PmergeMe() {};
    PmergeMe(PmergeMe const &cpy);
    PmergeMe const &operator=(PmergeMe const &other);

    PmergeMe(std::vector<int> array) : vec(array), _pairs(1) {}
    PmergeMe(std::deque<int> array) : deque_vec(array), _pairs(1) {}
    long  jacobsthal(long n);

    //Ford Johnson with std::vector
    std::vector<int> ford_johnson(PmergeMe &stack);
    template <typename T>
    void print_lst(std::vector<T> lst);
    void swap(int *nb1, int *nb2);
    void swap_range(int start, int end, int start_swap, int end_swap);
    void binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> &nb, int idx_nb, int pair);


    //Ford Johnson with std::set
    std::deque<int> ford_johnson_deque(PmergeMe &stack);
    template <typename T>
    void print_lst(std::deque<T> lst);
    void swap_range_deque(int start, int end, int start_swap, int end_swap);
    void binary_insertion(std::deque<int> &tab, int tab_idx, std::deque<int> &nb, int idx_nb, int pair);

};
