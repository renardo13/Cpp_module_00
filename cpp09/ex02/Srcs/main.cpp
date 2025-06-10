#include "../Includes/PmergeMe.hpp"
#include <climits>
#include <ctime>

int	PmergeMe::get_max(std::deque<int> tabv, int idx, int end)
{
	int max = tabv[idx];
	while (idx < end)
	{
		if (idx + 1 == end)
			return (max);
		if (max < tabv[idx + 1])
			max = tabv[idx + 1];
		idx++;
	}
	return (max);
}

bool PmergeMe::is_sorted(std::vector<int> tab, int begin, int step)
{
	for (int i = begin; i + step < static_cast<int>(tab.size()); i += step)
	{
		if (tab[i] > tab[i + step])
			return false;
	}
	return true;
}


bool PmergeMe::is_sorted(std::deque<int> tabd, int begin, int step)
{
	int max_left = get_max(tabd, begin, begin + step / 2);
	int max_right = get_max(tabd, begin + (step / 2), begin + step);
	if (max_left < max_right)
		return (true);
	return (false);
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
			stack = vector.ford_johnson_vector(vector, 2);
			clock_t end = clock();

			clock_t deque_start = clock();
			stack_deque = deque.ford_johnson_deque(deque, 2);
			clock_t deque_end = clock();

			std::cout
				<< "After ->  ";
			vector.print_lst(stack_deque);

			double duration_us = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
			double deque_duration_us = (double)(deque_end - deque_start) / CLOCKS_PER_SEC * 1000000;
			std::cout << "Time to process a range of " << stack.size() << " elements with std::vector "
					  << duration_us << " us" << std::endl;

			std::cout << "Time to process a range of " << stack.size() << " elements with std::deque  "
					  << deque_duration_us << " us" << std::endl;
		}
	}
}