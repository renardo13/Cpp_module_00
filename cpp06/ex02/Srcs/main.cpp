#include "../Includes/A.hpp"
#include "../Includes/B.hpp"
#include "../Includes/C.hpp"
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