#include "Bureaucrat.hpp"

int main(void)
{
	// 관료1 (제대로 됨)
	try
	{
		Bureaucrat James("James", 100);
		James.upGrade();
		James.downGrade();
	}
	catch (std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// 관료2 (잘못된 생성)
	try
	{
		Bureaucrat Hammond("James", -1); // 이 이후의 코드를 무시한다.
		Hammond.upGrade();
		Hammond.downGrade();
	}
	catch (std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
	std::cout << std::endl;


	// 관료3 (잘못된 승진)
	try {
		Bureaucrat Choi("Choi", 15);
		Choi.upGrade(180);  // 이 이후의 코드를 무시한다.
		Choi.downGrade();
	}
	catch (std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
	std::cout << std::endl;

	// 관료4 (잘못된 강등)
	try {
		Bureaucrat Lee("Lee", 120);
		Lee.upGrade();
		Lee.downGrade(190); // 이 이후의 코드를 무시한다.
	}
	catch (std::exception &e) {
		std::cout << "error : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}