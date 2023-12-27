#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    // 스코프
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) 
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	// 배열 범위 초과
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

	// 배열 범위 초과
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
		numbers[i] = rand();
	delete [] mirror;

	try {
		Array<int> arr2(0);
		arr2[0] = 0;
	}
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

	return 0;
}