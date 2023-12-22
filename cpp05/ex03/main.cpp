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
}