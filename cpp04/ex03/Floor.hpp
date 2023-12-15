#pragma once
#include "AMateria.hpp"

class Floor
{
	private:
		AMateria *slot[4];

	public:
		// orthodox canonical form
		Floor();
		Floor(const Floor &other);
		Floor &operator=(const Floor &other);
		~Floor();

		//member function
		void additem(int idx, AMateria *item);
};