#pragma once
#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;

	public:
		// orthodox canonical form
		Dog();
		Dog(const Dog &other);
		Dog operator=(const Dog &other);
		~Dog();

		// overriding
		void makeSound() const;
};