#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		// orthodox canonical form
		Dog();
		Dog(const Dog &other);
		Dog operator=(const Dog &other);
		~Dog();

		// overriding
		void makeSound() const;
};