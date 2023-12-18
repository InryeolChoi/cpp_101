#include "ShrubberyCreationForm.hpp"

// private
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("_target")
{}

// public
ShrubberyCreationForm::ShrubberyCreationForm(std::string str)
	: AForm("ShrubberyCreationForm", 145, 137), target(str)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other.getName(), other.getSignGrade(), other.getExeGrade()), target(other.target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

// member function
std::string ShrubberyCreationForm::getTarget()
{
	return (target);
}

// override
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	(void) executor;
	std::ofstream outFile((target + std::string("_shrubbery")).c_str());

	if (outFile)
	{
		outFile << "    /\\    \n";
		outFile << "   /  \\   \n";
		outFile << "  /    \\  \n";
		outFile << " /      \\ \n";
		outFile << "/________\\\n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";

		outFile.close();
	}
	else
		throw ShrubberyCreationForm::OpenFileException();
}

// exceptions
const char *ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return ("error : failed to open");
}