#include "Intern.hpp"

// orthodox canonical form
Intern::Intern()
{}

Intern::Intern(Intern const &other)
{
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	if (this != &other) {}
	return (*this);
}

Intern::~Intern()
{}

// member function
AForm *makeForm(std::string s1, std::string s2)
{
	for (int i = 0; i < 3; i++)
		if (names[i] == s1)
			return (this->*(forms[i]))(s2);
	throw FormNotFoundException();

}

const char*	Intern::FormNotFoundException::what() const throw() {
	return "<Intern> Form not found! May I bring you a coffee instead?";
}