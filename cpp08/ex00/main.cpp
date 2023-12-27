#include "easyfind.hpp"

#include <vector>
int main(void)
{
	std::vector<int> vec(5);
	for (int i = 0; i < 5; i++)
		vec[i] = i;

	try
	{
		std::cout << std::distance(vec.begin(), easyfind(vec, 4)) << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}