#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// orthodox canonical form
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat operator=(const WrongCat &other);
		~WrongCat();

		// overriding
		void makeSound() const;
};