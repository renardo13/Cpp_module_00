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
    // Vectors
    std::vector<int> vec;
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<int> odd;
    std::vector<int> tmp;

    // Deques
    std::deque<int> deque_vec;
    std::deque<int> deque_main;
    std::deque<int> deque_pend;
    std::deque<int> deque_odd;
    std::deque<int> deque_tmp;

public:
    // Constructors & Destructor
    PmergeMe() {}
    ~PmergeMe() {}
    PmergeMe(const PmergeMe &cpy);
    PmergeMe &operator=(const PmergeMe &other);

    PmergeMe(std::vector<int> array);
    PmergeMe(std::deque<int> array);

    // Utility
    long jacobsthal(long n);

    // Ford-Johnson with std::vector
    std::vector<int> ford_johnson_vector(PmergeMe &stack, int pair);
    void binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> &nb, int idx_nb, int pair);
    void swap(int *nb1, int *nb2);
    void swap_range(int start, int end, int start_swap, int end_swap);
    bool is_sorted(std::vector<int> tab, int begin, int step);
    int get_max(std::vector<int> tab, int idx, int end);

    // Ford-Johnson with std::deque
    std::deque<int> ford_johnson_deque(PmergeMe &stack, int pair);
    void binary_insertion(std::deque<int> &tab, int tab_idx, std::deque<int> &nb, int idx_nb, int pair);
    void swap_range_deque(int start, int end, int start_swap, int end_swap);
    bool is_sorted(std::deque<int> tab, int begin, int step);
    int get_max(std::deque<int> tab, int idx, int end);

    template <typename T>
    void print_lst(const std::vector<T> &lst)
    {
        for (size_t i = 0; i < lst.size(); ++i)
            std::cout << lst[i] << " ";
        std::cout << std::endl;
    }

    template <typename T>
    void print_lst(const std::deque<T> &lst)
    {
        for (size_t i = 0; i < lst.size(); ++i)
            std::cout << lst[i] << " ";
        std::cout << std::endl;
    }
};
