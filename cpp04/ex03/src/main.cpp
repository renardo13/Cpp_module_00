#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

/* int main()
{
    // Materia initialization
    AMateria *ice = new Ice();
    AMateria *cure = new Cure();

    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
	src->learnMateria(new Cure());

    std::cout << std::string(40, '*') << std::endl;
    // Declaration of the interface with character to have access to the interface methods
    ICharacter *IRoger = new Character("Roger");
    ICharacter *IJulie = new Character("Julie");

    IMateriaSource *steel = new MateriaSource();
    IMateriaSource *materia = new MateriaSource();

    std::cout << std::string(40, '*') << std::endl;
    // Use of the interface Icharacter's methods
    IRoger->use(3, *IJulie);
    IRoger->equip(ice);
    IJulie->use(0, *IRoger);
    IJulie->equip(ice);
    IJulie->equip(cure);
    IJulie->unequip(0);
    IJulie->use(1, *IRoger);

    std::cout << std::string(40, '-') << std::endl;
    // Use of the interface IMateriaSource's methods
    steel->createMateria("steel");
    materia->createMateria("ice");

    std::cout << std::string(40, '-') << std::endl;

    // Free memory
    delete ice;
    delete cure;
    delete IRoger;
    delete IJulie;
    delete src;
    delete steel;
    delete materia;
    return 0;
} */

int main()
{
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    // delete src;
    return 0;
}
