#pragma once
#include <iostream>

class WrongAnimal
{
	public:
		// orthodox canonical form
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal operator=(const WrongAnimal &other);
		~WrongAnimal();
};