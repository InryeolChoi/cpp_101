#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// void check_leaks()
// {
// 	system("leaks ex03");
// }

int main(void)
{
	// atexit(check_leaks);
	Bureaucrat	lee("lee", 1);
	Intern 		choi;
	AForm 		*form1, *form2, *form3, *form4;
	std::cout << std::endl;

	// "shrubbery creation", "robotomy request", "presidential pardon"

	// shrubbery creation
	try
	{
		form1 = choi.makeForm("shrubbery creation", "Kim");
		lee.signForm(*form1);
		lee.executeForm(*form1);
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	delete form1;
	std::cout << std::endl;

	// robotomy request
	try
	{
		form2 = choi.makeForm("robotomy request", "Kim");
		lee.signForm(*form2);
		lee.executeForm(*form2);
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	delete form2;
	std::cout << std::endl;

	// presidential pardon
	try
	{
		form3 = choi.makeForm("presidential pardon", "Kim");
		lee.signForm(*form3);
		lee.executeForm(*form3);
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	delete form3;
	std::cout << std::endl;

	// form4 (doesn't exist)
	try
	{
		form4 = choi.makeForm("42Seoul piscine restart", "Kim");
		lee.signForm(*form4);
		lee.executeForm(*form4);
	}
	catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
}