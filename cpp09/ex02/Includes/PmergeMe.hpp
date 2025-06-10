#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <exception>
# include <ctime>
# include <sstream>
# include <stdbool.h>
# include <cmath>
# include <deque>

# define RED     "\033[31m"
# define GREEN   "\033[0;32m"
# define RESET   "\033[0m"

class PmergeMe
{
	private:
		std::vector<int>	vec;
		std::deque<int>		deque;

	public:
		// Canonical Orthodox Form
		PmergeMe(void);
		PmergeMe(std::string* args, int size);
		~PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &src);

		// Parsing & sort algorithm methods
		void		parse_push(std::string input);
		void		ford_johnson_vec(std::vector<int> &vec, int pair);
		void		ford_johnson_deque(std::deque<int> &deque, int pair);
		static bool	is_integer(std::string str);
		long		jacobsthal(long n);

		// Vector sorting
		void	swap(std::vector<int> &tabv, int begin, int step);
		void	binary_insertion(std::vector<int> &tab, int tab_idx, std::vector<int> &nb, int idx_nb, int pair);
		bool 	is_sorted(const std::vector<int> &tabv, int begin, int step) const;
		int		get_max(const std::vector<int> &tabv, int idx, int end) const;
		
		// Deque sorting
		void	swap(std::deque<int> &tabl, int begin, int step);
		void	binary_insertion(std::deque<int> &tab, int tab_idx, std::deque<int> &nb, int idx_nb, int pair);
		bool	is_sorted(const std::deque<int> &tabd, int begin, int step) const;
		int		get_max(const std::deque<int> &tabd, int idx, int end) const;

};

#endif
