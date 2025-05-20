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
    stack.ford_johnson(stack);  // Recursive call
    _pairs /= 2;

    if (_pairs > arr_size / 4)
        return stack.vec;

    // Separation phase main, odd and pend
    nb_elements = arr_size / _pairs;
    if (nb_elements >= 4)
    {
        // Fill pend
        pend_start = _pairs * 2;
        for (; pend_start < (nb_elements - 1) * _pairs;)
        {
            stack.pend.insert(stack.pend.end(), stack.vec.begin() + pend_start,
                              stack.vec.begin() + pend_start + _pairs);
            pend_start += _pairs * 2;
        }
    }

    // Fill main
    stack.main.insert(stack.main.end(), stack.vec.begin(), stack.vec.begin() + _pairs * 2);
    main_start = _pairs * 3;
    for (; main_start <= (nb_elements - 1) * _pairs;)
    {
        stack.main.insert(stack.main.end(), stack.vec.begin() + main_start,
                          stack.vec.begin() + main_start + _pairs);
        main_start += _pairs * 2;
    }

    // Fill odd
    if (nb_elements % 2 == 1)
    {
        odd_start = (nb_elements - 1) * _pairs;
        stack.odd.insert(stack.odd.end(), stack.vec.begin() + odd_start,
                         stack.vec.begin() + odd_start + _pairs);
    }

	// Fusion of the elements
    j = 0;
    main_pair = 0;
    inserted_pend = 0;
    first_pend = 0;
    jacob_nb = 0;
    a = 0;
    b = 0;

    if (!stack.pend.empty())
    {
        while (!stack.pend.empty())
        {
            jacob_nb = jacobsthal(j++);
            first_pend = inserted_pend + 2;
            b = (((jacob_nb + 1) - (first_pend)) * _pairs) - 1;
            if (static_cast<unsigned long>(b) > (stack.pend.size() - 1))
            {
                b = stack.pend.size() - 1;
                jacob_nb = first_pend + (stack.pend.size() / _pairs);
            }
            main_pair = (b + 1) / _pairs;
            for (int i = 0; i < main_pair; i++)
            {
                a = (inserted_pend + jacob_nb) * _pairs - 1;
                binary_insertion(stack.main, a, stack.pend, b, 2 * _pairs);
                b -= _pairs;
                jacob_nb--;
                inserted_pend++;
            }
        }
    }
    if (!stack.odd.empty())
    {
        binary_insertion(stack.main, stack.main.size() - 1, stack.odd, stack.odd.size() - 1, 2 * _pairs);
    }

    stack.vec.clear();
    stack.vec.insert(stack.vec.end(), stack.main.begin(), stack.main.end());
    if (!stack.tmp.empty())
    {
        stack.vec.insert(stack.vec.end(), stack.tmp.begin(), stack.tmp.end());
    }

    // finalisation to sort the last pair
    if (!stack.pend.empty())
    {
        binary_insertion(stack.main, stack.main.size() - 1, stack.pend, stack.pend.size() - 1, 2 * _pairs);
    }
    if (!stack.odd.empty())
    {
        binary_insertion(stack.main, stack.main.size() - 1, stack.odd, stack.odd.size() - 1, 2 * _pairs);
    }

    // Clean the vector
    stack.pend.clear();
    stack.main.clear();
    stack.odd.clear();

    return stack.vec;
}

/* ---------------------------------------------------------------------The same algorithm with std::deque ------------------------------------------------------------------ */

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
    stack.ford_johnson_deque(stack);  // return in the recursion the swap value in the pair

    // Initialize main and odd stacks
    _pairs /= 2;
    if (_pairs > arr_size / 4)
        return stack.deque_vec;

    // Remplir pend et main
    nb_elements = arr_size / _pairs;
    if (nb_elements >= 4)
    {
        // loop to fill pend
        pend_start = _pairs * 2;
        for (; pend_start < (nb_elements - 1) * _pairs;)
        {
            stack.deque_pend.insert(stack.deque_pend.end(), stack.deque_vec.begin() + pend_start,
                                   stack.deque_vec.begin() + pend_start + _pairs);
            pend_start += _pairs * 2;
        }
    }

    // loop to fill main
    stack.deque_main.insert(stack.deque_main.end(), stack.deque_vec.begin(), stack.deque_vec.begin() + _pairs * 2);
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
        stack.deque_odd.insert(stack.deque_odd.end(), stack.deque_vec.begin() + odd_start,
                              stack.deque_vec.begin() + odd_start + _pairs);
    }

    j = 0;
    main_pair = 0;
    inserted_pend = 0;
    first_pend = 0;
    jacob_nb = 0;
    a = 0;
    b = 0;

    if (!stack.deque_pend.empty())
    {
        while (!stack.deque_pend.empty())
        {
            jacob_nb = jacobsthal(j++);
            first_pend = inserted_pend + 2;
            b = (((jacob_nb + 1) - (first_pend)) * _pairs) - 1;
            if (static_cast<unsigned long>(b) > (stack.deque_pend.size()) - 1)
            {
                // put the b to the last index of the pend
                b = stack.deque_pend.size() - 1;
                jacob_nb = first_pend + (stack.deque_pend.size() / _pairs);
            }
            main_pair = (b + 1) / _pairs;
            for (int i = 0; i < main_pair; i++)
            {
                a = (inserted_pend + jacob_nb) * _pairs - 1;
                binary_insertion(stack.deque_main, a, stack.deque_pend, b, 2 * _pairs);
                b -= _pairs;
                jacob_nb--;
                inserted_pend++;
            }
        }
    }

    // Si pend est vide et que odd existe
    if (!stack.deque_odd.empty())
    {
        binary_insertion(stack.deque_main, stack.deque_main.size() - 1, stack.deque_odd, stack.deque_odd.size() - 1, 2 * _pairs);
    }

    // Réorganisation finale des éléments dans deque_vec
    stack.deque_vec.clear();
    stack.deque_vec.insert(stack.deque_vec.end(), stack.deque_main.begin(), stack.deque_main.end());
    if (!stack.deque_tmp.empty())
    {
        stack.deque_vec.insert(stack.deque_vec.end(), stack.deque_tmp.begin(), stack.deque_tmp.end());
    }

    // Finalisation du tri : dernière itération pour la dernière paire non triée
    // Si la taille de `pend` ou `odd` est petite, on peut avoir des éléments non triés
    if (!stack.deque_pend.empty())
    {
        binary_insertion(stack.deque_main, stack.deque_main.size() - 1, stack.deque_pend, stack.deque_pend.size() - 1, 2 * _pairs);
    }
    if (!stack.deque_odd.empty())
    {
        binary_insertion(stack.deque_main, stack.deque_main.size() - 1, stack.deque_odd, stack.deque_odd.size() - 1, 2 * _pairs);
    }

    // Nettoyage des structures intermédiaires
    stack.deque_pend.clear();
    stack.deque_main.clear();
    stack.deque_odd.clear();

    return stack.deque_vec;
}

long PmergeMe::jacobsthal(long n)
{
	return ((pow(2, n + 3) - pow(-1, n + 1)) / 3);
}