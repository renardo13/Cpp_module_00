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
        this->vec = cpy.vec;
}

PmergeMe const &PmergeMe::operator=(PmergeMe const &other)
{
    if (this != &other)
    {
        this->vec = other.vec;
        // this->_array_arr = other._array_arr;}
    }
    return (*this);
}

void PmergeMe::swap_range(int start, int end, int swap_start, int swap_end)
{
    // std::cout << "start " << start << " end " << end << " swap_start " << swap_start << " swap_end " << swap_end << std::endl;
    std::vector<int> tmp;
    std::vector<int>::iterator it = vec.begin() + swap_start;

    int range = end - start;
    for (int i = 0; i < start; i++)
        tmp.push_back(vec[i]);
    for (int i = 0; i <= range; i++, it++)
        tmp.push_back(*it);
    it = vec.begin() + start;
    for (int i = 0; i <= range; i++, it++)
        tmp.push_back(*it);
    for (size_t i = swap_end + 1; i < vec.size(); i++)
        tmp.push_back(vec[i]);
    vec.clear();
    vec = tmp;
}

// Jump is the number of elements that we skip while itering
// _pairs is the number of elements that we use to form pairs
void PmergeMe::ford_johnson(PmergeMe &stack)
{
    int arr_size = stack.vec.size();
    if (stack._pairs >= arr_size / 2)
        return;
    int jump = stack._pairs;
    while (jump + stack._pairs - 1 < arr_size)
    {
        if (stack.vec[jump - 1] > stack.vec[jump + stack._pairs - 1])
            stack.swap_range(jump - stack._pairs, jump - 1, jump, jump + stack._pairs - 1);
        jump += stack._pairs * 2;
    }
    stack._pairs *= 2;
    stack.ford_johnson(stack); // return in the recursion the swap value in the pair
    // Initialize main and odd stacks
    stack._pairs /= 2;
    if (stack._pairs > arr_size / 4)
        return;
    // print_lst(stack.vec);
    // return ;

    int nb_elements = arr_size / stack._pairs;
    if (nb_elements >= 4)
    {
        // loop to fill pend
        int pend_start = stack._pairs * 2;
        for (;pend_start < (nb_elements - 1) * stack._pairs;)
        {
            stack.pend.insert(pend.end(), stack.vec.begin() + pend_start, stack.vec.begin() + pend_start + stack._pairs);
            pend_start += stack._pairs * 2;
            std::cout << "pend -> " ;
            print_lst(stack.pend);
        }
    }

    // loop to fill main
    stack.main.insert(main.end(), stack.vec.begin(), stack.vec.begin() + stack._pairs * 2);
    int main_start = stack._pairs * 3;
    for (;main_start < nb_elements * stack._pairs;)
    {
            stack.pend.insert(pend.end(), stack.vec.begin() + pend_start, stack.vec.begin() + pend_start + stack._pairs);
    }
    std::cout << "main -> " ;
    print_lst(stack.main);

    std::cout << std::string(40, '_') << std::endl;
    stack.pend.clear();
    stack.main.clear();
    return ;
    for (int i = 0;;)
    {
        if (i + stack._pairs <= arr_size)
            for (int j = 0; j < stack._pairs; j++)
                main.push_back(stack.vec[i++]);
        else if (stack.vec[i])
        {
            odd.push_back(stack.vec[i++]);
        }
    }

    if (stack._pairs < arr_size / 2)
    {
        std::cout << "stack pairs = " << stack._pairs << std::endl;
        std::cout << "main : ";
        print_lst(main);
        std::cout << "odd : ";
        print_lst(odd);
        add_pend(stack._pairs);
        std::cout << "pend : ";
        print_lst(pend);
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

void PmergeMe::add_pend(int pairs)
{
    int jump = pairs / 2;
    int start = pairs;
    tmp = main;

    while (start < (int)main.size() - jump)
    {
        pend.insert(pend.end(), main.begin() + start, main.begin() + start + jump);
        start += jump * 2;
    }
}