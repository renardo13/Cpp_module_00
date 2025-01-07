#include "RPN.hpp"

template <typename T> void print_deque(std::deque<T> lst)
{
	typename std::deque<T>::iterator it = lst.begin();
	for (; it != lst.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int	isOperator(char c)
{
	if (c == '*' || c == '/' || c == '+' || c == '-')
		return (1);
	return (0);
}

int	parse_input(const std::string &s)
{
	std::istringstream ss(s);
	std::string token;
	while (ss >> token)
	{
		if (token.size() == 1 && !isdigit(token[0]) && !isOperator(token[0]))
		{
			std::cout << "Invalid character: " << token << std::endl;
			return (-1);
		}
		if (isdigit(token[0]) && isdigit(token[1]))
		{
			std::cout << "Number should be less than 10." << std::endl;
			return (-1);
		}
		if (token.size() > 1 && !isdigit(token[0]))
		{
			std::cout << "Invalid number: " << token << std::endl;
			return (-1);
		}
	}
	return (0);
}

int	do_op(int nb1, int nb2, char op)
{
	if (op == '*')
		return (nb1 * nb2);
	if (op == '/')
		return (nb1 / nb2);
	if (op == '-')
		return (nb1 - nb2);
	if (op == '+')
		return (nb1 + nb2);
	return (0);
}

int	main(int ac, char **av)
{
	int	i;
	int	nb1;
	int	nb2;

	if (ac == 2)
	{
		if (parse_input(av[1]))
			return (-1);
		else
		{
			std::deque<int> stack;
			i = -1;
			while (av[1][++i])
			{
				if (std::isdigit(av[1][i]))
					stack.push_back(av[1][i] - 48);
				else if (isOperator(av[1][i]))
				{
					if (stack.size() < 2)
					{
						std::cout << "Error: Not enough operands for operation." << std::endl;
						return (-1);
					}
					if (!stack.empty())
					{
						nb1 = stack.back();
						stack.pop_back();
					}
					if (!stack.empty())
					{
						nb2 = stack.back();
						stack.pop_back();
					}
					stack.push_back(do_op(nb2, nb1, av[1][i]));
				}
			}
			if (stack.size() > 1)
			{
				std::cout << "Error: Not enough operators." << std::endl;
				return (-1);
			}
			std::cout << stack.front() << std::endl;
		}
	}
	else
		std::cout << "Wrong input format should be ./RPN \"expression\" " << std::endl;
}
