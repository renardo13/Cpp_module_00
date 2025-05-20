#include "../Includes/PmergeMe.hpp"
#include <climits>
#include <ctime>

template <typename T>
void PmergeMe::print_lst(std::vector<T> lst)
{
	typename std::vector<T>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T>
void PmergeMe::print_lst(std::deque<T> lst)
{
	typename std::deque<T>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int is_digit(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != 32)
		{
			return 0;
		}
	}
	return 1;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		{
			// std::vector
			std::vector<int> stack;
			std::deque<int> stack_deque;
			std::istringstream ss(av[1]);
			if (!is_digit(av[1]))
			{
				std::cout << "Error, character other than digit are not allowed" << std::endl;
				return (0);
			}
			long double num;
			while (ss >> num)
			{
				if (num > INT_MAX)
				{
					std::cout << "Error, number exceeds INT_MAX" << std::endl;
					return 0;
				}
				if (num < 0)
				{
					std::cout << "Error, number cannot be negative" << std::endl;
					return (0);
				}
				stack.push_back(num);
				stack_deque.push_back(num);
			}

			PmergeMe vector(stack);
			PmergeMe deque(stack_deque);

			std::cout
				<< "Before -> ";
			vector.print_lst(stack);

			clock_t start = clock();
			stack = vector.ford_johnson(vector);
			clock_t end = clock();

			clock_t deque_start = clock();
			stack_deque = deque.ford_johnson_deque(deque);
			clock_t deque_end = clock();

			std::cout
				<< "After ->  ";
			vector.print_lst(stack);

			double duration_us = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
			double deque_duration_us = (double)(deque_end - deque_start) / CLOCKS_PER_SEC * 1000000;
			std::cout << "Time to process a range of " << stack.size() << " elements with std::vector "
					  << duration_us << " us" << std::endl;

			std::cout << "Time to process a range of " << stack.size() << " elements with std::deque  "
					  << deque_duration_us << " us" << std::endl;
		}
	}
}