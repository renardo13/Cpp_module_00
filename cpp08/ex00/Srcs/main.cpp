#include "../Includes/easyfind.hpp"
#include <vector>

int main(void)
{
    std::vector<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);

    std::cout << easyfind(list, 3) << std::endl;
}