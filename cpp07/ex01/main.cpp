#include "iter.hpp"
#include <cctype>

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_plus(int &num)
{
	num++;
}

int main()
{
	char arr1[] = {'A', 'B', 'C'};
	std::cout << "< before >" << std::endl;

	for (size_t i = 0; i < sizeof(arr1); i++)
		std::cout << i << " : " << arr1[i] << std::endl;

	::iter(arr1, sizeof(arr1) / sizeof(char), ft_tolower);

	std::cout << "< after >" << std::endl;
	for (size_t i = 0; i < sizeof(arr1); i++)
		std::cout << i << " : " << arr1[i] << std::endl;

	std::cout << std::endl;

	int arr2[] = {1, 2, 3};
	std::cout << "< before >" << std::endl;
	for (size_t i = 0; i < sizeof(arr1); i++)
		std::cout << i << " : " << arr2[i] << std::endl;

	::iter(arr2, sizeof(arr2) / sizeof(int), ft_plus);

	std::cout << "< after >" << std::endl;
	for (size_t i = 0; i < sizeof(arr1); i++)
		std::cout << i << " : " << arr2[i] << std::endl;
}