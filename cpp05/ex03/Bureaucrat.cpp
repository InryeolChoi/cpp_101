#include "Bureaucrat.hpp"

// orthodox canonical form
Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << getName() << " becomes bureaucrat!!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}

// construtor overload
Bureaucrat::Bureaucrat(std::string str, int number) : name(str)
{
	this->setGrade(number);
	std::cout << getName() << " becomes bureaucrat!!" << std::endl;
}

// member function
void Bureaucrat::setGrade(int number)
{
	if (number > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (number < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade = number;
}

std::string	Bureaucrat::getName() const 
{
	return (name);
}

int Bureaucrat::getGrade(void)
{
	return (grade);
}

void Bureaucrat::upGrade()
{
	setGrade(grade - 1);
	std::cout << getName() << "'s grade is now " << getGrade();
	std::cout << std::endl;
}

void Bureaucrat::upGrade(int number)
{
	setGrade(grade - number);
	std::cout << getName() << "'s grade is now " << getGrade();
	std::cout << std::endl;
}

void Bureaucrat::downGrade()
{
	setGrade(grade + 1);
	std::cout << getName() << "'s grade is now " << getGrade();
	std::cout << std::endl;
}

void Bureaucrat::downGrade(int number)
{
	setGrade(grade + number);
	std::cout << getName() << "'s grade is now" << getGrade();
	std::cout << std::endl;
}

// new member function in ex01 
void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signs ";
		std::cout << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't sign " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

// new member function in ex02
void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " cannot execute " << form.getName();
		std::cout << " because " << e.what() << std::endl;
	}
}

// Exceptions
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

// overloading operator <<
std::ostream& operator<<(std::ostream &output, Bureaucrat &member)
{
	output << member.getName() << ", " << "bureaucrat grade ";
	output << member.getGrade() << std::endl;
	return (output);
}