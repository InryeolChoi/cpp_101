#pragma once
#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		// Orthodox Canonical form
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		// member function
		virtual void makeSound() const;
		void setType(std::string str);
		std::string getType() const;
};