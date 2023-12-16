#include "Bureaucrat.hpp"

// orthodox canonical form
Bureaucrat::Bureaucrat() : grade(1), name("default")
{}

Bureaucrat::Bureaucrat(const Bureaucrat &other) 
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{}

Bureaucrat::~Bureaucrat()
{}

// member function
void Bureaucrat::setGrade(int num)
{
	try
	{
		if (num < 0 || num > 150)
			throw std::out_of_range("invaild grade");
		grade = num;
	}
	catch (std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::string	Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade(void)
{
	return (grade);
}

void Bureaucrat::upGrade(int num)
{
	try
	{
		if (num == 0)
			throw 
	}
	catch ( &e)
	{

	}
}

void Bureaucrat::downGrade(int num)
{
	try
	{

	}
	catch ( &e)
	{

	}
}

// overloading operator <<
std::ostream& operator<<(std::string name, int grade)
{

}