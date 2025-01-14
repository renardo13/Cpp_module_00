#include "../Includes/PmergeMe.hpp"

template <typename T> void PmergeMe::print_lst(std::vector<T> lst)
{
	typename std::vector<T>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int	main(int ac, char **av)
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
            std::cout << std::endl << "Before -> ";
			merge.print_lst(stack);
			merge.ford_johnson(merge);
			std::cout << std::endl << "After ->  ";
			merge.print_lst(stack);
			std::cout << std::endl;
		}
	}
}