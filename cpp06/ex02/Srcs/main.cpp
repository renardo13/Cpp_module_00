#include "../Includes/Base.hpp"

int main(void)
{
    Base* parent = new B();

    parent = generate();

    if (parent)
        identify(*parent);
    else
        std::cout << "Parent is NULL, cannot call identify." << std::endl;

    delete parent;
    
}