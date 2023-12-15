#pragma once
#include "ICharacter.hpp"

class AMateria; // 전방 선언

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria *inventory[4];

	public:
		// orthodox canonical form
		Character();
		Character(const Character &other);
		Character &operator=(const Character &other);
		virtual ~Character();

		// member function
		Character(std::string str);
		std::string const &getName(void) const;
		void equip(AMateria *materia);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};