#pragma once
#include "Brain.hpp"
#include "AAnimal.hpp"

class Dog : public AAnimal
{
	private:
		Brain *brain;

	public:
		// orthodox canonical form
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		// overriding
		void makeSound() const;
		Brain *getBrain() const;
};