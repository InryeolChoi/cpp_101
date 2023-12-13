#pragma once
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;

	public:
		// Orthodox Canonical form
		AMateria(std::string const &type);

		std::string const &getType() const;

		virtual AMateria *clone() const = 0; // 순수 가상함수
		virtual void use(ICharacter &target) = 0; // 순수 가상함수
}