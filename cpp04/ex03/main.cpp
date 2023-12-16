#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>

// void checkleaks()
// {
// 	system("leaks ex03");
// }

int main()
{
	// atexit(checkleaks);

	// 기술 저장고에 기술 저장
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// 캐릭터 생성
	Character *npc1 = new Character("npc1");
	Character *npc2 = new Character("npc2");

	// materia 생성
	AMateria *item1 = src->createMateria("Ice");
	if (item1)
		npc1->equip(item1);

	AMateria *item2 = src->createMateria("Cure");
	if (item2)
		npc2->equip(item2);
	std::cout << std::endl;

	// 기술 사용
	std::cout << "use npc1's materia" << std::endl;
	npc1->use(0, *npc2);
	std::cout << "use npc2's materia" << std::endl;
	npc2->use(0, *npc2);
	std::cout << std::endl;

	// unequip (once unequip, you can't equip anymore)
	npc1->unequip(0);
	npc2->unequip(0);

	// 캐릭터 해제
	delete npc1;
	delete npc2;

	// 저장창고 해제
	delete src;
	return 0;
}