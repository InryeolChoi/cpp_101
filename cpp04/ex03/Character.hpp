#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		// orthodox canonical form
		Character();
		Character(const Character &other);
		Character operator=(const Character &other);
		~Character();

		// member function
		void unequip();
}