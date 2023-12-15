#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
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
	
	// 기술 사용
	npc1->use(0, *npc2);
	npc2->use(0, *npc2);

	delete src;
	delete npc1;
	delete npc2;

	return 0;
}