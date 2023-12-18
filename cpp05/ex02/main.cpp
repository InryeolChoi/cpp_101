#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	// 관료 생성
	Bureaucrat inchoi("inchoi", 1);

	// form 생성
	try
	{
		ShrubberyCreationForm form("home");
		inchoi.signForm(form);
		inchoi.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "error : " << e.what() << std::endl;
	}

	// 

	return 0;
}