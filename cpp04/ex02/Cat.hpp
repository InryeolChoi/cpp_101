#pragma once
#include "Brain.hpp"
#include "AAnimal.hpp"

class Cat : public AAnimal
{
	private:
		Brain *brain;

	public:
		// orthodox canonical form
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();

		// overriding
		void makeSound() const;
		Brain *getBrain() const;
};