#include "Brain.hpp"

/* orthodox canonical form */
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "idea";
}

Brain::Brain(const Brain &obj)
{
	*this = obj;
}

Brain &Brain::operator=(const Brain &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return (*this);
}

Brain::~Brain() {}

/* member function */
void Brain::setidea(int i, std::string str)
{
	if (i >= 0 && i < 100)
		ideas[i] = str;
	else
		std::cout << "wrong index" << std::endl;
}

std::string Brain::getidea(int i)
{
	return (ideas[i]);
}