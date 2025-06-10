#include "PmergeMe.hpp"
#include <sstream>
#include <cmath>
#include <ctime>
#include <iostream>

// Constructeurs / destructeur / opérateur d'assignation

PmergeMe::PmergeMe(void)
{
	throw std::runtime_error("No arguments are given!");
}

PmergeMe::PmergeMe(std::string* args, int size)
{
	for (int i = 0; i < size; i++)
		parse_push(args[i]);

	// Affichage avant tri
	std::cout << GREEN << "Before: " << RESET;
	for (std::vector<int>::iterator itv1 = vec.begin(); itv1 != vec.end(); ++itv1)
		std::cout << *itv1 << " ";
	std::cout << std::endl;

	// Tri vector et mesure du temps
	clock_t start_v = clock();
	ford_johnson_vec(this->vec, 2);
	clock_t end_v = clock();
	double diff_vec = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC * 1000000;

	// Affichage après tri vector
	std::cout << GREEN << "After:  " << RESET;
	for (std::vector<int>::iterator itv2 = vec.begin(); itv2 != vec.end(); ++itv2)
		std::cout << *itv2 << " ";
	std::cout << std::endl;

	// Tri deque et mesure du temps
	clock_t start_l = clock();
	ford_johnson_deque(this->deque, 2);
	clock_t end_l = clock();
	double diff_list = static_cast<double>(end_l - start_l) / CLOCKS_PER_SEC * 1000000;

	// Affichage temps traitement
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector<int> : " << diff_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size() << " elements with std::deque<int>  : " << diff_list << " us" << std::endl;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		this->deque = src.deque;
		this->vec = src.vec;
	}
	return *this;
}

// Parsing

void PmergeMe::parse_push(std::string input)
{
	std::stringstream sinput;
	long nb;

	if (!is_integer(input))
		throw std::runtime_error("Error: " + input + " is not an integer");
	sinput << input;
	sinput >> nb;
	if (nb < 0)
		throw std::runtime_error("Error: " + input + " is a negative integer");
	if (nb > 2147483647)
		throw std::runtime_error("Error: " + input + " overflows int type capacity");
	vec.push_back(nb);
	deque.push_back(nb);
}

bool PmergeMe::is_integer(std::string str)
{
	std::string::iterator it = str.begin();
	if (*it == '0' && str.length() > 1)
		throw std::runtime_error("Error: " + str + " is in wrong format");
	else if (*it == '-')
		it++;
	for (; it != str.end(); ++it)
	{
		if (*it < '0' || *it > '9')
			return false;
	}
	return true;
}

// Utils tri

long PmergeMe::jacobsthal(long n)
{
	return ((pow(2, n + 3) - pow(-1, n + 1)) / 3);
}

// Fonctions pour vector

void PmergeMe::swap(std::vector<int> &tabv, int begin, int step)
{
	std::vector<int> temp;
	temp.insert(temp.begin(), tabv.begin() + begin, tabv.begin() + begin + (step / 2));

	for (int i = begin; i < begin + (step / 2); i++)
		tabv[i] = tabv[i + (step / 2)];
	for (int i = begin + (step / 2); i < begin + step; i++)
		tabv[i] = temp[i - (begin + (step / 2))];
}

void PmergeMe::binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> &nb, int idx_nb, int pair)
{
	while (tab_idx >= 0 && tab[tab_idx] > nb[idx_nb])
		tab_idx -= pair / 2;
	if (tab_idx < 0)
		tab.insert(tab.begin(), nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	else
		tab.insert(tab.begin() + tab_idx + 1, nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	nb.erase(nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
}

bool PmergeMe::is_sorted(std::vector<int> const &tabv, int begin, int step) const
{
	int max_left = get_max(tabv, begin, begin + step / 2);
	int max_right = get_max(tabv, begin + (step / 2), begin + step);
	return (max_left < max_right);
}

int PmergeMe::get_max(std::vector<int> const &tabv, int idx, int end) const
{
	int max = tabv[idx];
	while (idx < end - 1)
	{
		if (max < tabv[idx + 1])
			max = tabv[idx + 1];
		idx++;
	}
	return max;
}

void PmergeMe::ford_johnson_vec(std::vector<int> &vec, int pair)
{
	int v_size = static_cast<int>(vec.size());
	if (v_size / pair < 1)
		return;
	for (int begin = 0; begin < v_size; begin += pair)
	{
		if (begin + pair > v_size)
			break;
		if (!is_sorted(vec, begin, pair))
			swap(vec, begin, pair);
	}
	ford_johnson_vec(vec, pair * 2);

	std::vector<int> main;
	main.insert(main.begin(), vec.begin(), vec.begin() + pair);

	std::vector<int> pend;
	std::vector<int> odd;
	std::vector<int> temp;
	int main_nb = 0;

	for (int i = pair; i < v_size; i += pair)
	{
		if (i + pair > v_size)
		{
			if (i + pair / 2 - 1 < v_size)
				odd.insert(odd.begin(), vec.begin() + pair * (main_nb + 1), vec.begin() + pair * (main_nb + 1) + (pair / 2));
			if (v_size % (pair / 2) != 0)
				temp.insert(temp.begin(), vec.end() - (v_size % (pair / 2)), vec.end());
			break;
		}
		main.insert(main.begin() + main.size(), vec.begin() + pair * (main_nb + 1) + (pair / 2), vec.begin() + pair * (main_nb + 2));
		pend.insert(pend.begin() + pend.size(), vec.begin() + pair * (main_nb + 1), vec.begin() + pair * (main_nb + 1) + (pair / 2));
		main_nb++;
	}

	int j = 0;
	int main_pair = 0;
	int inserted_pend = 0;
	int first_pend = 0;
	int jacob_nb = 0;
	int a = 0;
	int b = 0;

	if (!pend.empty())
	{
		while (!pend.empty())
		{
			jacob_nb = jacobsthal(j++);
			first_pend = inserted_pend + 2;
			b = (((jacob_nb + 1) - (first_pend)) * (pair / 2)) - 1;
			if (static_cast<unsigned long>(b) > pend.size() - 1)
			{
				b = pend.size() - 1;
				jacob_nb = first_pend + ((pend.size() / (pair / 2)));
			}
			main_pair = (b + 1) / (pair / 2);
			for (int i = 0; i < main_pair; i++)
			{
				a = (inserted_pend + jacob_nb) * (pair / 2) - 1;
				binary_insertion(main, a, pend, b, pair);
				b -= (pair / 2);
				jacob_nb--;
				inserted_pend++;
			}
		}
		if (!odd.empty())
			binary_insertion(main, main.size() - 1, odd, odd.size() - 1, pair);
		vec.clear();
		vec.insert(vec.begin(), main.begin(), main.end());
		if (!temp.empty())
			vec.insert(vec.end(), temp.begin(), temp.end());
	}
	else if (!odd.empty())
	{
		binary_insertion(main, main.size() - 1, odd, odd.size() - 1, pair);
		vec.clear();
		vec.insert(vec.begin(), main.begin(), main.end());
		if (!temp.empty())
			vec.insert(vec.end(), temp.begin(), temp.end());
	}
}

// Fonctions pour deque (idem que vector, adapté)

void PmergeMe::swap(std::deque<int> &tabd, int begin, int step)
{
	std::deque<int> temp;
	temp.insert(temp.begin(), tabd.begin() + begin, tabd.begin() + begin + (step / 2));

	for (int i = begin; i < begin + (step / 2); i++)
		tabd[i] = tabd[i + (step / 2)];
	for (int i = begin + (step / 2); i < begin + step; i++)
		tabd[i] = temp[i - (begin + (step / 2))];
}

void PmergeMe::binary_insertion(std::deque<int> &tab, int tab_idx, std::deque<int> &nb, int idx_nb, int pair)
{
	while (tab_idx >= 0 && tab[tab_idx] > nb[idx_nb])
		tab_idx -= pair / 2;
	if (tab_idx < 0)
		tab.insert(tab.begin(), nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	else
		tab.insert(tab.begin() + tab_idx + 1, nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	nb.erase(nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
}

bool PmergeMe::is_sorted(std::deque<int> const &tabd, int begin, int step) const
{
	int max_left = get_max(tabd, begin, begin + step / 2);
	int max_right = get_max(tabd, begin + (step / 2), begin + step);
	return (max_left < max_right);
}

int PmergeMe::get_max(std::deque<int> const &tabd, int idx, int end) const
{
	int max = tabd[idx];
	while (idx < end - 1)
	{
		if (max < tabd[idx + 1])
			max = tabd[idx + 1];
		idx++;
	}
	return max;
}

void PmergeMe::ford_johnson_deque(std::deque<int> &deque, int pair)
{
	int d_size = static_cast<int>(deque.size());
	if (d_size / pair < 1)
		return;
	for (int begin = 0; begin < d_size; begin += pair)
	{
		if (begin + pair > d_size)
			break;
		if (!is_sorted(deque, begin, pair))
			swap(deque, begin, pair);
	}
	ford_johnson_deque(deque, pair * 2);

	std::deque<int> main;
	main.insert(main.begin(), deque.begin(), deque.begin() + pair);

	std::deque<int> pend;
	std::deque<int> odd;
	std::deque<int> temp;
	int main_nb = 0;

	for (int i = pair; i < d_size; i += pair)
	{
		if (i + pair > d_size)
		{
			if (i + pair / 2 - 1 < d_size)
				odd.insert(odd.begin(), deque.begin() + pair * (main_nb + 1), deque.begin() + pair * (main_nb + 1) + (pair / 2));
			if (d_size % (pair / 2) != 0)
				temp.insert(temp.begin(), deque.end() - (d_size % (pair / 2)), deque.end());
			break;
		}
		main.insert(main.begin() + main.size(), deque.begin() + pair * (main_nb + 1) + (pair / 2), deque.begin() + pair * (main_nb + 2));
		pend.insert(pend.begin() + pend.size(), deque.begin() + pair * (main_nb + 1), deque.begin() + pair * (main_nb + 1) + (pair / 2));
		main_nb++;
	}

	int j = 0;
	int main_pair = 0;
	int inserted_pend = 0;
	int first_pend = 0;
	int jacob_nb = 0;
	int a = 0;
	int b = 0;

	if (!pend.empty())
	{
		while (!pend.empty())
		{
			jacob_nb = jacobsthal(j++);
			first_pend = inserted_pend + 2;
			b = (((jacob_nb + 1) - (first_pend)) * (pair / 2)) - 1;
			if (static_cast<unsigned long>(b) > pend.size() - 1)
			{
				b = pend.size() - 1;
				jacob_nb = first_pend + ((pend.size() / (pair / 2)));
			}
			main_pair = (b + 1) / (pair / 2);
			for (int i = 0; i < main_pair; i++)
			{
				a = (inserted_pend + jacob_nb) * (pair / 2) - 1;
				binary_insertion(main, a, pend, b, pair);
				b -= (pair / 2);
				jacob_nb--;
				inserted_pend++;
			}
		}
		if (!odd.empty())
			binary_insertion(main, main.size() - 1, odd, odd.size() - 1, pair);
		deque.clear();
		deque.insert(deque.begin(), main.begin(), main.end());
		if (!temp.empty())
			deque.insert(deque.end(), temp.begin(), temp.end());
	}
	else if (!odd.empty())
	{
		binary_insertion(main, main.size() - 1, odd, odd.size() - 1, pair);
		deque.clear();
		deque.insert(deque.begin(), main.begin(), main.end());
		if (!temp.empty())
			deque.insert(deque.end(), temp.begin(), temp.end());
	}
}
