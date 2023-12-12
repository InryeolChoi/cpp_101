#pragma once
#include "Brain.hpp"
#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;

	public:
		// orthodox canonical form
		Cat();
		Cat(const Cat &other);
		Cat operator=(const Cat &other);
		~Cat();

		// overriding
		void makeSound() const;
};