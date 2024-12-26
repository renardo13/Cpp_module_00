#include "../Includes/iter.hpp"

template<typename T>
void add1(T& target)
{
    target++;
}

template<typename T>
void ToUpper(T& target)
{
    target += 32;
}

size_t strlen(std::string s)
{
    size_t i = 0;

    while(s[i])
        s[i];
    return(i);
}

int main()
{
    char s[]= "Salut ca va ?";
    iter(s, strlen(s), ToUpper<char>);
    std::cout << s << std::endl;

    std::cout << std::string(40, '-') << std::endl;
    int tab[]= {0, 1, 2, 3, 4};
    iter(tab, 5, add1<int>);
    for(int i = 0; i < 5; i++)
        std::cout << tab[i];

    std::cout << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    char tab1[] = {'a', 'b', 'c', 'b', 'z'};
    iter(tab1, strlen(tab1), add1<char>);
    for(int i = 0; i < 5; i++)
        std::cout << tab1[i];



}