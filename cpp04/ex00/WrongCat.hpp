#pragma once
#include "WrongAnimal.hpp"

class WrongCat
{
	public:
		// orthodox canonical form
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat operator=(const WrongCat &other);
		~WrongCat();
};