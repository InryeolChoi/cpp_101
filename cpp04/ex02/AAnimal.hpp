#pragma once
#include <iostream>

class AAnimal
{
	protected:
		std::string type;

	public:
		// Orthodox Canonical form
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal();

		// others & member function
		// 추상클래스이므로, 클래스에 순수 가상함수를 포함함.
		AAnimal(std::string str);
		virtual void makeSound() const = 0;
		void setType(std::string str);
		std::string getType() const;
};