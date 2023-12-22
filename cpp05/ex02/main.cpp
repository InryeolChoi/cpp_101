#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	// 관료 생성
	Bureaucrat Son("Son", 50);
	Bureaucrat Lee("Lee", 60);
	Bureaucrat Kim("Kim", 30);
	std::cout << std::endl;

	// Shrbe(145, 137)
	// Robot(72, 45)
	// Presi(25, 5)

	// form 생성 1 : Shruberry, sign 성공, exec 성공
	try
	{
		ShrubberyCreationForm form1("home");
		Son.signForm(form1);
		Son.executeForm(form1);
	}
	catch (std::exception &e)
	{
		std::cout << "error : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// form 생성 2 : RobotomyRequest, sign 성공, exec 실패
	try
	{
		RobotomyRequestForm form2("home");
		Lee.signForm(form2);
		Lee.executeForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << "error : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// form 생성 3 : Presidential
	try
	{
		PresidentialPardonForm form3("home");
		Kim.signForm(form3);
		Kim.executeForm(form3);
	}
	catch (std::exception &e)
	{
		std::cout << "error : " << e.what() << std::endl;
	}
	return 0;
}