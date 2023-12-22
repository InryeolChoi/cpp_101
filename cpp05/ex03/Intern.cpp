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
static AForm *form_Presi(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *form_Robot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *form_Shrubery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string s1, std::string s2)
{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*form[])(const std::string target) = {&form_Shrubery, &form_Presi, &form_Robot};
	// AForm * : return 값을 의미.
	// *form[] : 배열의 타입이 포인터임을 의미
	// 각 form-creating function은 static function으로 설계

	// simple for-if structure (not nested)
	for (int i = 0; i < 3; i++)
	{
		if (s1 == types[i])
			return form[i](s2);
	}
	throw Intern::FormNotFoundException();
	return (NULL);
}

const char*	Intern::FormNotFoundException::what() const throw() {
	return "<Intern> Form not found! May I bring you a coffee instead?";
}