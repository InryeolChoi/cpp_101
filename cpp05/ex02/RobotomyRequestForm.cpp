#include "RobotomyRequestForm.hpp"

// private
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), target("_target")
{}

// public
RobotomyRequestForm::RobotomyRequestForm(std::string str)
	: AForm("RobotomyRequestForm", 72, 45), target(str)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other.getName(), other.getSignGrade(), other.getExeGrade()), target(other.target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

// member function
std::string RobotomyRequestForm::getTarget()
{
	return (target);
}

// override
void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	std::srand(static_cast<unsigned int>(std::time(0)));

	if (std::rand() % 2 == 0)
	{
		std::cout << executor.getName() << " has been robotimized";
		std::cout << std::endl;
	}
	else
	{
		std::cout << executor.getName() << " has been failed";
		std::cout << std::endl;
	}
}