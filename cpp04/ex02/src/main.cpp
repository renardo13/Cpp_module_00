#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

int main(void)
{
    // const Animal *dog = new Dog();
    // const Animal *cat = new Cat();

    // we need double pointer here
    //Cure is a type of AMateria so it is possible to copy it, it is polymorphism
    Animal *anim[10];

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            anim[i] = new Cat();
        }
        else
        {
            anim[i] = new Dog();
        }
        std::cout << std::string(30, '*') << std::endl;
    }
    std::cout << std::string(30, '|') << std::endl;
    std::cout << std::string(30, '-') << std::endl;

    Cat* cat = dynamic_cast<Cat*>(anim[0]);

    std::cout << cat->getBrain()->getIdeas(4) << std::endl;

    std::cout << std::string(30, '-') << std::endl;
    std::cout << std::string(30, '|') << std::endl;
    std::cout << std::string(30, '-') << std::endl;
    // When deleting the destructor is called
    for (int i = 0; i < 10; i++)
    {
        delete anim[i];
        std::cout << std::string(30, '*') << std::endl;
    }

    // delete dog; // should not create a leak
    // delete cat;

    return 0;
}