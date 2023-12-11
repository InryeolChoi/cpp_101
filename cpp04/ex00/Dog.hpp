#pragma once
#include "Animal.hpp"

class Dog : protected Animal
{
	public:
		// orthodox canonical form
		Dog();
		Dog(const Dog &other);
		Dog operator=(const Dog &other);
		~Dog();

		// overriding
		void makeSound();
};