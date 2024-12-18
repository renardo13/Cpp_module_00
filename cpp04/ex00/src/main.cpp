#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main(void)
{
    const WrongAnimal* meta = new WrongAnimal();
    const Animal* dog = new Dog();
    const WrongAnimal* cat = new WrongCat();

    std::cout << std::string(40, '*') << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

    std::cout << std::string(40, '*') << std::endl;
    dog->makeSound(); // will output the cat sound!
    cat->makeSound();
    meta->makeSound();
    std::cout << std::string(40, '*') << std::endl;

    /* ___________________________________________________ */

    Animal* Animal;

    Animal = new Cat();

    std::cout << "Type of the animal after initialize by Animal class " << Animal->getType() << std::endl;
    Animal->makeSound();
    std::cout << std::string(40, '*') << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete Animal;
    return (0);
}
