#pragma once
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string type;

	public:
		// Orthodox Canonical form
		AMateria();
		AMateria(AMateria const &other);
		AMateria &operator=(AMateria const &other);
		virtual ~AMateria();

		// member function
		AMateria(std::string const &type);
		std::string const &getType() const;
		void setType(std::string str);

		// virtual function
		virtual AMateria *clone() const = 0;	// 순수 가상함수
		virtual void use(ICharacter &target);	// 가상함수
};