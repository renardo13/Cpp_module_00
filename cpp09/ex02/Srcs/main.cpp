#include "../Includes/PmergeMe.hpp"

template<typename T>
    void print_lstt(std::vector<T> lst)
{
    typename std::vector<T>::iterator it = lst.begin();

    for (; it != lst.end(); it++)
        std::cout << *it << " ";
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        {
            std::vector<int> stack;
            std::istringstream ss(av[1]);

            int num;
            while (ss >> num)
            {
                stack.push_back(num);
            }
            PmergeMe merge(stack);
            merge.ford_johnson(merge);
            // print_lstt(stack);
            std::cout << std::endl;
        }
    }
}