#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

int main(void)
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();


    delete dog;//should not create a leak
    delete cat;

    return 0;
}