#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	// 관료 생성
	Bureaucrat inchoi("inchoi", 10);
	std::cout << inchoi;
	std::cout << std::endl;

	Bureaucrat Kim("Kim", 2);
	std::cout << Kim;
	std::cout << std::endl;

	// 국책사업1 : 42서울 지원
	try
	{
		Form support42("support42", 11, 12);
		std::cout << support42;
		inchoi.signForm(support42);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// 국책사업2 : 분당선급행
	try
	{
		Form rapidBundang("rapidBundang", 3, 12);
		std::cout << rapidBundang;
		inchoi.signForm(rapidBundang);	// 싸인 불가능
		Kim.signForm(rapidBundang);		// 싸인 가능

		// 재사인 (불가능)
		Kim.signForm(rapidBundang);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// 국책사업3 : 한국판 실리콘벨리
	try
	{
		Form kSliconValley("kSliconValley", 2, 2);
		std::cout << kSliconValley;
		inchoi.signForm(kSliconValley);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// 국책사업4 : 수능에 컴퓨터과학 과목 추가 (폼 자체가 불가능)
	try
	{
		Form add_CS_to_CSAT("add_CS_to_CSAT", 0, -1); // 등급이 너무 높음.
		std::cout << add_CS_to_CSAT;
		inchoi.signForm(add_CS_to_CSAT);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}


	return 0;
}