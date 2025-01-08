#include "PmergeMe.hpp"
#include <algorithm>

template <typename T>
void PmergeMe::print_lst(std::vector<T> lst)
{
    typename std::vector<T>::iterator it = lst.begin();

    for (; it != lst.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::swap(int *nb1, int *nb2)
{
    int tmp = *nb1;
    *nb1 = *nb2;
    *nb2 = tmp;
}

PmergeMe::PmergeMe(PmergeMe const &cpy)
{
    if (this != &cpy)
        this->_array_lst = cpy._array_lst;
}

PmergeMe const &PmergeMe::operator=(PmergeMe const &other)
{
    if (this != &other)
    {
        this->_array_lst = other._array_lst;
        // this->_array_arr = other._array_arr;}
    }
    return (*this);
}

void PmergeMe::swap_range(int start, int end, int swap_start, int swap_end)
{
    // std::cout << "start " << start << " end " << end << " swap_start " << swap_start << " swap_end " << swap_end << std::endl;
    std::vector<int> tmp;
    std::vector<int>::iterator it = _array_lst.begin() + swap_start;

    int range = end - start;
    for (int i = 0; i < start; i++)
        tmp.push_back(_array_lst[i]);
    for (int i = 0; i <= range; i++, it++)
        tmp.push_back(*it);
    it = _array_lst.begin() + start;
    for (int i = 0; i <= range; i++, it++)
        tmp.push_back(*it);
    for (size_t i = swap_end + 1; i < _array_lst.size(); i++)
        tmp.push_back(_array_lst[i]);
    _array_lst.clear();
    _array_lst = tmp;
}

// Jump is the number of elements that we skip while itering
// _pairs is the number of elements that we use to form pairs
std::vector<int> PmergeMe::ford_johnson(PmergeMe &stack)
{
    std::vector<int>::iterator it;
    size_t jump = stack._pairs;
    while (jump + stack._pairs - 1 < (unsigned int)(stack._array_lst.size()))
    {
        if (stack._array_lst[jump - 1] > stack._array_lst[jump + stack._pairs - 1])
            stack.swap_range(jump - stack._pairs, jump - 1, jump, jump + stack._pairs - 1);
        jump += stack._pairs * 2;
    }
    stack._pairs *= 2;
    if (stack._pairs >= (int)stack._array_lst.size() / 2)
        return (stack._array_lst);
    stack.ford_johnson(stack); // return in the recursion the swap value in the pair
    // Initialize main and odd stacks
    stack._pairs /= 2;
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<int> odd;
    std::cout << stack._pairs << std::endl;

    for (size_t i = 0; i <= stack._array_lst.size() - stack._pairs / 2 + 1;)
    {
        if (i + stack._pairs <= stack._array_lst.size())
            for (size_t j = 0; j < (size_t)stack._pairs; j++)
                main.push_back(stack._array_lst[i++]);
        else if (stack._array_lst[i])
        {
            odd.push_back(stack._array_lst[i++]);
        }
    }

    if (stack._pairs < (int)(stack._array_lst.size() / 2))
    {
    std::cout << "stack pairs = " << stack._pairs << std::endl;
        std::cout << "main : ";
        print_lst(main);
        std::cout << "odd : ";
        print_lst(odd);
        add_pend(stack._pairs, pend, odd.size(), main);
        std::cout << "pend : ";
        print_lst(pend);
        std::cout << std::endl;
    }
    return (stack._array_lst);
}

void PmergeMe::add_pend(int pairs, std::vector<int> &pend, int odd_size, std::vector<int> main)
{
    int jump = pairs * 2;
    (void)odd_size;
    int start = pairs * 2; // handle the fact that we have to start at "b2"
    while (start < (int)main.size())
    {
        pend.insert(pend.end(), main.begin() + start, main.begin() + start + (jump / 2));
        start += jump;
    }
}