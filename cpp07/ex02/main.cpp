#include "Array.hpp"
#include <cstdlib>
#include <iostream>

int main(void)
{
	// 배열 체크
	srand(time(NULL));
	Array<int> arr1(10);
	for (unsigned int i = 0; i < arr1.size(); i++)
		arr1[i] = rand();



	// scope 체크
	try 
	{
		Array<int> tmp;
		tmp[1];
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}


}