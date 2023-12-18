#include "PresidentialPardonForm.hpp"

// private, constructor
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("ShrubberyCreation", 25, 5), target("_target")
{}

// public, orthodox canonical form
PresidentialPardonForm::PresidentialPardonForm(std::string str)
	: AForm("ShrubberyCreation", 25, 5), target(str)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
	: AForm(other.getName(), other.getSignGrade(), other.getExeGrade()), target(other.target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

// member function
std::string PresidentialPardonForm::getTarget()
{
	return (target);
}

// override
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void) executor;
	std::cout << target << " was pardoned by Zaphod Beeblebrox!" << std::endl;
}