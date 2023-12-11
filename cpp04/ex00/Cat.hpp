#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		// orthodox canonical form
		Cat();
		Cat(const Cat &other);
		Cat operator=(const Cat &other);
		~Cat();

		// overriding
		void makeSound();
};