#include "PmergeMe.hpp"

void swap(int *nb1, int *nb2)
{
    std::cout << "COUCOU" << std::endl;
    int tmp = *nb1;
    *nb1 = *nb2;
    *nb2 = tmp;
}

PmergeMe::PmergeMe(PmergeMe const &cpy)
{
    if (this != &cpy)
        *this = cpy;
}

PmergeMe const &PmergeMe::operator=(PmergeMe const &other)
{
    this->_array_lst = other._array_lst;
    // this->_array_arr = other._array_arr;
    return (*this);
}

std::list<int> PmergeMe::ford_johnson(std::list<int>& lst)
{
    PmergeMe stack(lst);
    std::list<int>::iterator it;

    if (lst.size() <= 1)
        return (lst);
    it = lst.begin();

    int jump = stack._recursion_level * 2;
    std::list<int>::iterator next_it = it;
    std::advance(next_it, 1);
    for (; it != lst.end(); it++)
    {
        std::cout << "Comparing: " << *it << " and " << *next_it << std::endl;
        if (next_it != lst.end() && *it > *next_it)
        {
            swap(&(*it), &(*next_it));
             std::cout << "Swapping: " << *it << " and " << *next_it << std::endl;
        }
        std::advance(it, jump);
    }

    return (stack._array_lst);
}