#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat	lee("lee", 10);
	Intern 		choi;

	// "shrubbery creation", "robotomy request", "presidential pardon"
	try
	{
		AForm *form1 = choi.makeForm("shrubbery creation", "Kim");
		lee.signForm(*form1);
		lee.executeForm(*form1);
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		for (int i = 0; i < 10; i++)
		{
			AForm *form2 = choi.makeForm("robotomy request", "Kim");
			lee.signForm(*form2);
			lee.executeForm(*form2);
		}
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		AForm *form3 = choi.makeForm("presidential pardon", "Kim");
		lee.signForm(*form3);
		lee.executeForm(*form3);
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		AForm *form3 = choi.makeForm("42Seoul piscine restart", "Kim");
		lee.signForm(*form3);
		lee.executeForm(*form3);
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
}