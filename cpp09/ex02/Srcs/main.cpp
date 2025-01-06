#include "../Includes/PmergeMe.hpp"

template<typename T>
void print_lst(std::list<T> lst)
{
    typename std::list<T>::iterator it = lst.begin();

    for(; it != lst.end(); it++)
        std::cout << *it << " ";
}



int main(int ac, char **av)
{
    if (ac == 2)
    {
        {
            std::list<int> stack;
            std::istringstream ss(av[1]);

            int num;
            while (ss >> num)
            {
                stack.push_back(num);
            }
            PmergeMe PmergeMe(stack);
            stack = PmergeMe.ford_johnson(stack);
            print_lst(stack);
            std::cout << std::endl;
        }
    }
}