#include "PmergeMe.hpp"
#include <algorithm>


void PmergeMe::swap(int *nb1, int *nb2)
{
	int tmp;

	tmp = *nb1;
	*nb1 = *nb2;
	*nb2 = tmp;
}

PmergeMe::PmergeMe(PmergeMe const &cpy)
	: vec(cpy.vec), deque_vec(cpy.deque_vec), deque_main(cpy.deque_main),
	  deque_pend(cpy.deque_pend), deque_odd(cpy.deque_odd)
{
}

PmergeMe const &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
		this->vec = other.vec;
	return (*this);
}

void PmergeMe::swap_range(int start, int end, int swap_start, int swap_end)
{
	int range;

	std::vector<int> temp;
	std::vector<int>::iterator it = vec.begin() + swap_start;
	range = end - start;
	for (int i = 0; i < start; i++)
		temp.push_back(vec[i]);
	for (int i = 0; i <= range; i++, it++)
		temp.push_back(*it);
	it = vec.begin() + start;
	for (int i = 0; i <= range; i++, it++)
		temp.push_back(*it);
	for (size_t i = swap_end + 1; i < vec.size(); i++)
		temp.push_back(vec[i]);
	vec.clear();
	vec = temp;
}

void PmergeMe::binary_insertion(std::vector<int> &tab, int tab_idx,
								std::vector<int> &nb, int idx_nb, int pair)
{
	while (tab_idx >= 0 && tab[tab_idx] > nb[idx_nb])
		tab_idx -= pair / 2;
	if (tab_idx < 0)
		tab.insert(tab.begin(), nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	else
		tab.insert(tab.begin() + tab_idx + 1, nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	nb.erase(nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
}

// Jump is the number of elements that we skip while itering
// _pairs is the number of elements that we use to form pairs
std::vector<int> PmergeMe::ford_johnson(PmergeMe &stack)
{
	int arr_size;
	int jump;
	int nb_elements;
	int pend_start;
	int main_start;
	int odd_start;
	int j;
	int main_pair;
	int inserted_pend;
	int first_pend;
	int jacob_nb;
	int a;
	int b;

	arr_size = stack.vec.size();
	if (_pairs >= arr_size / 2)
		return stack.vec;
	jump = _pairs;
	while (jump + _pairs - 1 < arr_size)
	{
		if (stack.vec[jump - 1] > stack.vec[jump + _pairs - 1])
			stack.swap_range(jump - _pairs, jump - 1, jump, jump + _pairs - 1);
		jump += _pairs * 2;
	}
	_pairs *= 2;
	stack.ford_johnson(stack);
	// return in the recursion the swap value in the pair
	// Initialize main and odd stacks
	_pairs /= 2;
	if (_pairs > arr_size / 4)
		return stack.vec;

	nb_elements = arr_size / _pairs;
	if (nb_elements >= 4)
	{
		// loop to fill pend
		pend_start = _pairs * 2;
		for (; pend_start < (nb_elements - 1) * _pairs;)
		{
			stack.pend.insert(pend.end(), stack.vec.begin() + pend_start,
							  stack.vec.begin() + pend_start + _pairs);
			pend_start += _pairs * 2;
		}
	}
	// loop to fill main
	stack.main.insert(main.end(), stack.vec.begin(), stack.vec.begin() + _pairs * 2);
	main_start = _pairs * 3;
	for (; main_start <= (nb_elements - 1) * _pairs;)
	{
		stack.main.insert(stack.main.end(), stack.vec.begin() + main_start,
						  stack.vec.begin() + main_start + _pairs);
		main_start += _pairs * 2;
	}
	// fill odd if it exists
	if (nb_elements % 2 == 1)
	{
		odd_start = (nb_elements - 1) * _pairs;
		stack.odd.insert(odd.end(), stack.vec.begin() + odd_start,
						 stack.vec.begin() + odd_start + _pairs);
	}

	j = 0;
	main_pair = 0;
	inserted_pend = 0;
	first_pend = 0;
	jacob_nb = 0;
	a = 0;
	b = 0;

	if (pend.size() != 0)
	{
		while (pend.size() != 0)
		{
			jacob_nb = jacobsthal(j++);
			first_pend = inserted_pend + 2;
			b = (((jacob_nb + 1) - (first_pend)) * _pairs) - 1;
			if (static_cast<unsigned long>(b) > (pend.size() - 1))
			{
				// put the b to the last index of the pend
				b = pend.size() - 1;
				jacob_nb = first_pend + ((pend.size() / _pairs));
			}
			main_pair = (b + 1) / _pairs;
			for (int i = 0; i < main_pair; i++)
			{
				a = (inserted_pend + jacob_nb) * _pairs - 1;
				binary_insertion(main, a, pend, b, 2 * _pairs);
				b -= _pairs;
				jacob_nb--;
				inserted_pend++;
			}
		}
		if (odd.size() != 0)
			binary_insertion(main, (main.size() - 1), odd, odd.size() - 1, 2 * _pairs);
		vec.erase(vec.begin(), vec.end());
		vec.insert(vec.begin(), main.begin(), main.end());
		if (tmp.size() != 0)
			vec.insert(vec.begin() + vec.size(), tmp.begin(), tmp.end());
	}
	else if (odd.size() != 0)
	{
		binary_insertion(main, (main.size() - 1), odd, odd.size() - 1, 2 * _pairs);
		vec.erase(vec.begin(), vec.end());
		vec.insert(vec.begin(), main.begin(), main.end());
		if (tmp.size() != 0)
			vec.insert(vec.begin() + vec.size(), tmp.begin(), tmp.end());
	}
	stack.pend.clear();
	stack.main.clear();
	stack.odd.clear();
	return stack.vec;
}

// std::deque
//  Fonction d'insertion binaire
void PmergeMe::binary_insertion(std::deque<int> &tab, int tab_idx,
								std::deque<int> &nb, int idx_nb, int pair)
{
	while (tab_idx >= 0 && tab[tab_idx] > nb[idx_nb])
	{
		tab_idx -= pair / 2;
	}
	if (tab_idx < 0)
	{
		tab.insert(tab.begin(), nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	}
	else
	{
		tab.insert(tab.begin() + tab_idx + 1, nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	}
	nb.erase(nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
}

// Fonction d'échange de plages
void PmergeMe::swap_range_deque(int start, int end, int swap_start, int swap_end)
{
	int range;

	std::deque<int> temp;
	std::deque<int>::iterator it = deque_vec.begin() + swap_start;
	range = end - start;
	for (int i = 0; i < start; i++)
		temp.push_back(deque_vec[i]);
	for (int i = 0; i <= range; i++, it++)
		temp.push_back(*it);
	it = deque_vec.begin() + start;
	for (int i = 0; i <= range; i++, it++)
		temp.push_back(*it);
	for (size_t i = swap_end + 1; i < deque_vec.size(); i++)
		temp.push_back(deque_vec[i]);
	deque_vec.clear();
	deque_vec = temp;
}

std::deque<int> PmergeMe::ford_johnson_deque(PmergeMe &stack)
{
	int arr_size;
	int jump;
	int nb_elements;
	int pend_start;
	int main_start;
	int odd_start;
	int j;
	int main_pair;
	int inserted_pend;
	int first_pend;
	int jacob_nb;
	int a;
	int b;

	arr_size = stack.deque_vec.size();
	if (_pairs >= arr_size / 2)
		return stack.deque_vec;
	jump = _pairs;
	while (jump + _pairs - 1 < arr_size)
	{
		if (stack.deque_vec[jump - 1] > stack.deque_vec[jump + _pairs - 1])
			stack.swap_range_deque(jump - _pairs, jump - 1, jump, jump + _pairs - 1);
		jump += _pairs * 2;
	}
	_pairs *= 2;
	stack.ford_johnson_deque(stack);
	// return in the recursion the swap value in the pair
	// Initialize main and odd stacks
	_pairs /= 2;
	if (_pairs > arr_size / 4)
		return stack.deque_vec;

	nb_elements = arr_size / _pairs;
	if (nb_elements >= 4)
	{
		// loop to fill pend
		pend_start = _pairs * 2;
		for (; pend_start < (nb_elements - 1) * _pairs;)
		{
			stack.deque_pend.insert(deque_pend.end(), stack.deque_vec.begin() + pend_start,
							  stack.deque_vec.begin() + pend_start + _pairs);
			pend_start += _pairs * 2;
		}
	}
	// loop to fill main
	stack.deque_main.insert(deque_main.end(), stack.deque_vec.begin(), stack.deque_vec.begin() + _pairs * 2);
	main_start = _pairs * 3;
	for (; main_start <= (nb_elements - 1) * _pairs;)
	{
		stack.deque_main.insert(stack.deque_main.end(), stack.deque_vec.begin() + main_start,
						  stack.deque_vec.begin() + main_start + _pairs);
		main_start += _pairs * 2;
	}
	// fill odd if it exists
	if (nb_elements % 2 == 1)
	{
		odd_start = (nb_elements - 1) * _pairs;
		stack.deque_odd.insert(deque_odd.end(), stack.deque_vec.begin() + odd_start,
						 stack.deque_vec.begin() + odd_start + _pairs);
	}

	j = 0;
	main_pair = 0;
	inserted_pend = 0;
	first_pend = 0;
	jacob_nb = 0;
	a = 0;
	b = 0;

	if (deque_pend.size() != 0)
	{
		while (deque_pend.size() != 0)
		{
			jacob_nb = jacobsthal(j++);
			first_pend = inserted_pend + 2;
			b = (((jacob_nb + 1) - (first_pend)) * _pairs) - 1;
			if (static_cast<unsigned long>(b) > (deque_pend.size() - 1))
			{
				// put the b to the last index of the pend
				b = deque_pend.size() - 1;
				jacob_nb = first_pend + ((deque_pend.size() / _pairs));
			}
			main_pair = (b + 1) / _pairs;
			for (int i = 0; i < main_pair; i++)
			{
				a = (inserted_pend + jacob_nb) * _pairs - 1;
				binary_insertion(deque_main, a, deque_pend, b, 2 * _pairs);
				b -= _pairs;
				jacob_nb--;
				inserted_pend++;
			}
		}
		if (deque_odd.size() != 0)
			binary_insertion(deque_main, (deque_main.size() - 1), deque_odd, deque_odd.size() - 1, 2 * _pairs);
		deque_vec.erase(deque_vec.begin(), deque_vec.end());
		deque_vec.insert(deque_vec.begin(), deque_main.begin(), deque_main.end());
		if (deque_tmp.size() != 0)
			deque_vec.insert(deque_vec.begin() + deque_vec.size(), deque_tmp.begin(), deque_tmp.end());
	}
	else if (deque_odd.size() != 0)
	{
		binary_insertion(deque_main, (deque_main.size() - 1), deque_odd, deque_odd.size() - 1, 2 * _pairs);
		deque_vec.erase(deque_vec.begin(), deque_vec.end());
		deque_vec.insert(deque_vec.begin(), deque_main.begin(), deque_main.end());
		if (deque_tmp.size() != 0)
			deque_vec.insert(deque_vec.begin() + deque_vec.size(), deque_tmp.begin(), deque_tmp.end());
	}
	stack.deque_pend.clear();
	stack.deque_main.clear();
	stack.deque_odd.clear();
	return stack.deque_vec;
}

long PmergeMe::jacobsthal(long n)
{
	return ((pow(2, n + 3) - pow(-1, n + 1)) / 3);
}