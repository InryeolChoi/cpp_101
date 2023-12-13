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

		// others & member function
		Animal(std::string str);
		virtual void makeSound() const = 0;
		void setType(std::string str);
		std::string getType() const;
};