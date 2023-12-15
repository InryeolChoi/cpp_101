#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *source[4];

	public:
		// orthodox canoncial form
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource &operator=(MateriaSource const &other);
		~MateriaSource();

		// others & member function
		void learnMateria(AMateria *materia);
		AMateria *createMateria(std::string const &type);
};