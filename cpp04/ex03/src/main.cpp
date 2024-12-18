#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

int main()
{
    AMateria *materia = new Ice();
    std::cout << std::string(40, '*') << std::endl;

    Character car;
    car.equip(materia);

    std::cout << std::string(40, '*') << std::endl;

    // std::cout << materia->getType() << std::endl;

    // IMateriaSource* src = new MateriaSource();
    // AMateria *mm = NULL;

    // std::cout << std::string(40, '*') << std::endl;

    // src->learnMateria(mm);
    // src->learnMateria(new Cure());
    // std::cout << std::string(40, '*') << std::endl;

    ICharacter* me = &car;
    // AMateria* tmp;

    // std::cout << std::string(40, '*') << std::endl;
    // tmp = src->createMateria("icee");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // std::cout << std::string(40, '*') << std::endl;

    // ICharacter* bob = &car;
    std::cout << std::string(40, '*') << std::endl;

    me->use(0, car);
    // me->use(1, *bob);

    // delete bob;
    // delete me;
    // delete src;
    // delete materia;
    return 0;
}