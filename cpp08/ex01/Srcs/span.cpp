#include "../Includes/span.hpp"

Span::Span() : _tab(0), _N(0) {}

Span::~Span() {}

Span::Span(Span const &cpy)
{
    if (this != &cpy)
        *this = cpy;
}

Span const &Span::operator=(Span const &other)
{
    this->_tab = other._tab;
    this->_N = other._N;
    return (*this);
}

Span::Span(unsigned int N) : _N(N)
{
    _tab.reserve(N);
}

void Span::addNumber(int nb)
{
    if (_tab.size() >= _N)
        throw(VectorIsFull());
    _tab.push_back(nb);
}
int Span::shortestSpan() const
{
    if (_tab.size() < 2)
        throw ImpossibleComparison();
    
    std::vector<int> sorted_lst = _tab;
    std::sort(sorted_lst.begin(), sorted_lst.end()); // By sorting the tab before, we make shure that the shortest difference will be between two adjacent numbers

    int shortest_diff = _tab.size();
    for (std::vector<int>::iterator it = sorted_lst.begin(); it != sorted_lst.end() - 1; ++it) 
    {
        int diff = *(it + 1) - *it;
        if (diff < shortest_diff)
            shortest_diff = diff;
    }
    return (shortest_diff);
}

int Span::longestSpan() const
{
    if(_tab.size() < 2)
        throw (ImpossibleComparison());
    
    std::vector<int> sorted_lst;
    sorted_lst = _tab;

    int end = sorted_lst.size();
    std::sort(sorted_lst.begin(), sorted_lst.end());
    return(abs(sorted_lst[0] - sorted_lst[end - 1]));
}


void Span::fillUpWithRange(unsigned int start, unsigned int end, int value)
{
    if(end > _N)
        throw(VectorIsFull());
     _tab.insert(_tab.begin() + start, end - start + 1, value);
}
