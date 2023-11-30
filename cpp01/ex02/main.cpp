#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN"; // 원 문자열
	std::string *stringPTR = &str; // 포인터
	std::string &stringREF = str; // 레퍼런스

	// 주소값 출력하기
	std::cout << "address of str : " << &str << std::endl;
	std::cout << "address of stringPTR : " << stringPTR << std::endl;
	std::cout << "address of stringRER : " << &stringREF << std::endl;


	// 값 출력하기
	std::cout << std::endl;
	std::cout << "value of str : " << str << std::endl;
	std::cout << "value of stringPTR : " << *stringPTR << std::endl;
	std::cout << "value of stringRER : " << stringREF << std::endl;
}