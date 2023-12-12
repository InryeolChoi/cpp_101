#pragma once
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		// Orthodox Canonical form
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		~WrongAnimal();
	
		// member function
		void makeSound() const;
		void setType(std::string str);
		std::string getType() const;
};