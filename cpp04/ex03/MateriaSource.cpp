#include "MateriaSource.hpp"

// orthodox canoncial form
MateriaSource::MateriaSource()
{}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (source[i])
				source[i] = other.source[i]->clone();
			else
				source[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i])
			delete source[i];
		else
			source[i] = NULL;
	}
}

// others & member function
void MateriaSource::learnMateria(AMateria *materia)
{
	if (materia->getType() != "ice" || materia->getType() != "cure")
	{
		std::cout << "type of materia is not valid." << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!source[i])
		{
			source[i] = materia;
			return ;
		}
	}
	std::cout << "we've learned all Materia." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (source[i] && source[i]->getType() == type)
			return (source[i]->clone());
	}
	std::cout << "error : not a vaild type" << std::endl;
	return (0);
}