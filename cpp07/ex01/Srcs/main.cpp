#include "../Includes/iter.hpp"

int main()
{
    std::string s = "Salut ca va ?";
    iter(s, s.length(), &toupper);

    
}