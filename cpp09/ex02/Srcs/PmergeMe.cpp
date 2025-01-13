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
        for (; pend_start < (nb_elements - 1) * stack._pairs;)
        {
            stack.pend.insert(pend.end(), stack.vec.begin() + pend_start, stack.vec.begin() + pend_start + stack._pairs);
            pend_start += stack._pairs * 2;
        }
    }

    // loop to fill main
    stack.main.insert(main.end(), stack.vec.begin(), stack.vec.begin() + stack._pairs * 2);
    int main_start = stack._pairs * 3;
    for (; main_start <= (nb_elements - 1) * stack._pairs;)
    {
        stack.main.insert(stack.main.end(), stack.vec.begin() + main_start, stack.vec.begin() + main_start + stack._pairs);
        main_start += stack._pairs * 2;
    }

    // fill odd if it exists
    if (nb_elements % 2 == 1)
    {
        int odd_start = (nb_elements - 1) * stack._pairs;
        stack.odd.insert(odd.end(), stack.vec.begin() + odd_start, stack.vec.begin() + odd_start + stack._pairs);
    }

    std::cout << std::endl
              << "main before -> ";
    print_lst(stack.main);
    std::cout
        << "pend before -> ";
    print_lst(stack.pend);

    stack.binary_insertion();

    std::cout << std::endl
              << "main after -> ";
    print_lst(stack.main);
    std::cout
        << "pend after -> ";
    print_lst(stack.pend);

    std::cout << std::string(40, '_') << std::endl;
    stack.pend.clear();
    stack.main.clear();
    stack.odd.clear();
}

// middle = (main.size() - pend.size()) \ 2

// 3 differents cases : Pend is empty, pend has one elements
// pend has 2 ore more elements and we use Jacobstal number

int PmergeMe::get_elem_index(int elem_id)
{
    return ((elem_id - 1) * _pairs);
}

// return the index where we have to insert nb in the vector
void PmergeMe::binary_search(int start, int end, int pend_index, int j, std::vector<int>& vec, std::vector<int>& tmp_vec)
{

    if (j < start || j > end)
    {
        return;
    }
    std::cout << "vec[pend_index] > main[j] " << vec[pend_index] << main[j] << std::endl;
    if (vec[pend_index] > main[j] && j + 1 >= end)
    {
        main.insert(main.begin() + j, tmp_vec.begin() + pend_index - _pairs + 1, tmp_vec.begin() + pend_index + 1);
        vec.erase(vec.begin() + pend_index - _pairs + 1, vec.begin() + pend_index + 1);
    }
    else if (pend[pend_index] <= main[j] && j - _pairs <= 0)
    {
        main.insert(main.begin(), tmp_vec.begin() + pend_index - _pairs + 1, tmp_vec.begin() + pend_index + 1);
        vec.erase(vec.begin() + pend_index - _pairs + 1, vec.begin() + pend_index + 1);
    }
    else if (pend[pend_index] > main[j])
    {
        int main_index = end - start;
        main_index += main_index / 2;
        if (main_index % 2 != 0)
        {
            main_index += 1;
        }
        binary_search(start, end, pend_index, main_index * _pairs, vec, tmp_vec);
    }
    else if (pend[pend_index] <= main[j])
    {
        int main_index = start + (end / 2);
        if (main_index % 2 != 0)
        {
            main_index -= 1;
        }
        binary_search(start, end, pend_index, main_index * _pairs, vec, tmp_vec);
    }
    // if()
}

void PmergeMe::binary_insertion()
{
    if (!pend.size())
        return;
    int pend_index = 0;
    if (_pairs > (int)pend.size())
        pend_index = _pairs * 2;
    else
        pend_index = _pairs;
    // int counter = 0;
    tmp = pend;
    int j = main.size() - pend.size();

        binary_search(0, j, pend_index - 1, j - 1, pend, tmp);
        binary_search(0, odd.size(), _pairs - 1, _pairs - 1, odd, odd);
    while (pend_index < (int)pend.size())
    {

        if (!odd.empty())
        {
            
        }
        pend_index += _pairs;
    }
}