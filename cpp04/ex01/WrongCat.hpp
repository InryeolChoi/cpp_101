#pragma once
#include "Brain.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		Brain *brain;

	public:
		// orthodox canonical form
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat operator=(const WrongCat &other);
		~WrongCat();

		// overriding
		void makeSound() const;

		// member function
		Brain *getBrain() const;
};