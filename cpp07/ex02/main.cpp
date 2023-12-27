#include "Array.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	// 배열 체크
	srand(time(NULL));
	Array<int> arr1(10);
	for (unsigned int i = 0; i < arr1.getsize(); i++)
		arr1[i] = i;
	std::cout << "arr1[2] : " << arr1[2] << std::endl;

	// scope 체크
	try 
	{
		Array<int> tmp;
		std::cout << "tmp[1] : " << tmp[1] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	// 복사생성자 체크
	Array<int> arr2(arr1);
	std::cout << "arr2[2] : " << arr2[2] << std::endl;

	// 대입연산자 체크
	Array<int> arr3(5);
	arr3 = arr2; // arr2의 배열 삭제 후 arr3 배열 이식
	try
	{
		std::cout << "arr3[4] : " << arr3[4] << std::endl;
		std::cout << "arr3[6] : " << arr3[6] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}