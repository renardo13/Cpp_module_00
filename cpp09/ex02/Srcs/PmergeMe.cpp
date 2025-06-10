#include "PmergeMe.hpp"
#include <algorithm>
#include <stdio.h>

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

std::vector<int> PmergeMe::ford_johnson_vector(PmergeMe &stack, int pair)
{
    int arr_size = stack.vec.size();

    if (arr_size / pair < 1)
        return stack.vec;

    // Trier les paires
    for (int begin = 0; begin < arr_size; begin += pair)
    {
        if (begin + pair > arr_size)
            break;
        if (!is_sorted(stack.vec, begin, pair))
            stack.swap_range(begin, begin + pair / 2 - 1, begin + pair / 2, begin + pair - 1);
    }

    // Snapshot local du vecteur trié récursivement
    PmergeMe temp_stack;
    temp_stack.vec = stack.vec;
    std::vector<int> sorted = ford_johnson_vector(temp_stack, pair * 2);

    // Préparer les conteneurs locaux
    std::vector<int> main;
    std::vector<int> pend;
    std::vector<int> odd;
    std::vector<int> tmp;

    int main_nb = 0;

    // Initialiser main avec la première paire
    main.insert(main.end(), sorted.begin(), sorted.begin() + pair);

    for (int i = pair; i < arr_size; i += pair)
    {
        if (i + pair > arr_size)
        {
            // Cas impair
            if (i + pair / 2 - 1 < arr_size)
                odd.insert(odd.end(), sorted.begin() + pair * (main_nb + 1),
                                     sorted.begin() + pair * (main_nb + 1) + (pair / 2));

            // Reste
            if (arr_size % (pair / 2) != 0)
                tmp.insert(tmp.end(), sorted.end() - (arr_size % (pair / 2)), sorted.end());
            break;
        }

        main.insert(main.end(), sorted.begin() + pair * (main_nb + 1) + (pair / 2),
                              sorted.begin() + pair * (main_nb + 2));

        pend.insert(pend.end(), sorted.begin() + pair * (main_nb + 1),
                              sorted.begin() + pair * (main_nb + 1) + (pair / 2));

        main_nb++;
    }

    // Insertion binaire avec Jacobsthal
    int j = 0;
    int inserted_pend = 0;
    while (!pend.empty())
    {
        int jacob_nb = jacobsthal(j++);
        int first_pend = inserted_pend + 2;
        int b = (((jacob_nb + 1) - (first_pend)) * (pair / 2)) - 1;

        if (static_cast<unsigned long>(b) > (pend.size() - 1))
        {
            b = pend.size() - 1;
            jacob_nb = first_pend + (pend.size() / (pair / 2));
        }

        int main_pair = (b + 1) / (pair / 2);
        for (int i = 0; i < main_pair; i++)
        {
            int a = (inserted_pend + jacob_nb) * (pair / 2) - 1;
            binary_insertion(main, a, pend, b, pair);
            b -= (pair / 2);
            jacob_nb--;
            inserted_pend++;
        }
    }

    // Insertion des impairs
    if (!odd.empty())
        binary_insertion(main, main.size() - 1, odd, odd.size() - 1, pair);

    // Fusion finale
    stack.vec.clear();
    stack.vec.insert(stack.vec.end(), main.begin(), main.end());
    if (!tmp.empty())
        stack.vec.insert(stack.vec.end(), tmp.begin(), tmp.end());

    return stack.vec;
}


/* ---------------------------------------------------------------------The same algorithm with std::deque ------------------------------------------------------------------ */

//  Fonction d'insertion binaire
void PmergeMe::binary_insertion(std::deque<int> &tab, int tab_idx,
								std::deque<int> &nb, int idx_nb, int pair)
{

	while (tab_idx >= 0 && tab[tab_idx] > nb[idx_nb])
		tab_idx -= pair / 2;
	if (tab_idx < 0)
		tab.insert(tab.begin(), nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
	else
		tab.insert(tab.begin() + tab_idx + 1, nb.begin() + idx_nb - (pair / 2) + 1, nb.begin() + idx_nb + 1);
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

std::deque<int> PmergeMe::ford_johnson_deque(PmergeMe &stack, int pair)
{
    int arr_size = stack.deque_vec.size();

    if (arr_size / pair < 1)
        return stack.deque_vec;

    // Sort pairs
    for (int begin = 0; begin < arr_size; begin += pair)
    {
        if (begin + pair > arr_size)
            break;
        if (!is_sorted(stack.deque_vec, begin, pair))
            stack.swap_range_deque(begin, begin + pair / 2 - 1, begin + pair / 2, begin + pair - 1);
    }

    // 👇 Stocker un snapshot local du tableau trié récursivement
    PmergeMe temp_stack;
    temp_stack.deque_vec = stack.deque_vec;
    std::deque<int> sorted = ford_johnson_deque(temp_stack, pair * 2);

    // Préparer les conteneurs locaux
    std::deque<int> main;
    std::deque<int> pend;
    std::deque<int> odd;
    std::deque<int> tmp;

    int main_nb = 0;

    // Initialiser main avec la première paire
    main.insert(main.end(), sorted.begin(), sorted.begin() + pair);

    for (int i = pair; i < arr_size; i += pair)
    {
        if (i + pair > arr_size)
        {
            // Odd
            if (i + pair / 2 - 1 < arr_size)
                odd.insert(odd.end(), sorted.begin() + pair * (main_nb + 1),
                                     sorted.begin() + pair * (main_nb + 1) + (pair / 2));

            // Temp
            if (arr_size % (pair / 2) != 0)
                tmp.insert(tmp.end(), sorted.end() - (arr_size % (pair / 2)), sorted.end());
            break;
        }

        main.insert(main.end(), sorted.begin() + pair * (main_nb + 1) + (pair / 2),
                              sorted.begin() + pair * (main_nb + 2));

        pend.insert(pend.end(), sorted.begin() + pair * (main_nb + 1),
                              sorted.begin() + pair * (main_nb + 1) + (pair / 2));

        main_nb++;
    }

    // Binary insertion using Jacobsthal
    int j = 0;
    int inserted_pend = 0;
    while (!pend.empty())
    {
        int jacob_nb = jacobsthal(j++);
        int first_pend = inserted_pend + 2;
        int b = (((jacob_nb + 1) - (first_pend)) * (pair / 2)) - 1;

        if (static_cast<unsigned long>(b) > (pend.size() - 1))
        {
            b = pend.size() - 1;
            jacob_nb = first_pend + (pend.size() / (pair / 2));
        }

        int main_pair = (b + 1) / (pair / 2);
        for (int i = 0; i < main_pair; i++)
        {
            int a = (inserted_pend + jacob_nb) * (pair / 2) - 1;
            binary_insertion(main, a, pend, b, pair);
            b -= (pair / 2);
            jacob_nb--;
            inserted_pend++;
        }
    }

    // Insertion des impairs
    if (!odd.empty())
        binary_insertion(main, main.size() - 1, odd, odd.size() - 1, pair);

    // Fusion finale
    stack.deque_vec.clear();
    stack.deque_vec.insert(stack.deque_vec.end(), main.begin(), main.end());
    if (!tmp.empty())
        stack.deque_vec.insert(stack.deque_vec.end(), tmp.begin(), tmp.end());

    return stack.deque_vec;
}


long PmergeMe::jacobsthal(long n)
{
	return ((pow(2, n + 3) - pow(-1, n + 1)) / 3);
}