#include "../Includes/span.hpp"

int& Span::operator[](unsigned int i)
{
    if(i >= 0 && i < this->_N)
        return(this->_tab[i]);
    throw std::out_of_range("index it's out of bounds");
}

/* int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
} */

int main(void)
{

    Span tab1(10);

    try {
        tab1.addNumber(1);
        tab1.addNumber(10);
        tab1.addNumber(3);
        tab1.addNumber(4);
        tab1.addNumber(5);
        tab1.addNumber(6);
        tab1.addNumber(7);
        tab1.addNumber(800);
        tab1.addNumber(9);
        tab1.addNumber(-10);
        std::cout << tab1.longestSpan() << std::endl;        
        std::cout << tab1.shortestSpan() << std::endl;
        tab1.fillUpWithRange(2, 6, 100);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    for (int i = 0; i != 10; i++)
        std::cout << tab1[i] << " ";
    std::cout << std::endl;



}