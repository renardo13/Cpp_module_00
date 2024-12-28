#include "../Includes/Array.hpp"
#include <cstdlib>

#define SIZE 10

template <typename T>
void swap(T &a, T &b)
{
    T tmp;

    tmp = b;
    b = a;
    a = tmp;
}

int main()
{
    // Test with INT
    Array<int> array1(SIZE);
    int tab1[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Use the operator [] to access the value os Array<T> and copy values inside
    try
    {
        for (size_t i = 0; i < SIZE; i++)
            array1[i] = tab1[i];
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < SIZE; i++)
        std::cout << array1[i];
    std::cout << std::endl;

    // Use a swap function for the elements <T> of the tab
    int tab2[SIZE] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (int i = 0; i < SIZE; i++)
        swap(array1[i], tab2[i]);

    for (int i = 0; i < SIZE; i++)
        std::cout << array1[i];
    std::cout << std::endl
              << std::endl;

    // Test with CHAR*
    std::cout << std::string(30, '-') << std::endl;
    const char *tab_char1[3] = {"Salut", "ca", "va"};
    Array<const char *> tab_char2(3);
    try
    {
        int i = 2;
        int j = 0;
        while (i >= 0)
        {
            tab_char2[j] = tab_char1[i];
            i--;
            j++;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << tab_char2[i];
        std::cout << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
        swap(tab_char2[i], tab_char1[i]);

    // std::cout to see the swap values
    for (int i = 0; i < 3; i++)
    {
        std::cout << tab_char2[i];
        std::cout << ' ';
    }
    std::cout << std::endl;
}
