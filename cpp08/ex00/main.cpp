#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec(5);
	for (int i = 0; i < 5; i++)
		vec[i] = i;

	std::deque<int> deque1;
	// front => 0 1 2 3 4 5 6 7 8 9 <= back
	for (int i = 0; i < 10; i++)
		deque1.push_back(i);

	// for (std::deque<int>::iterator it = deque1.begin(); it != deque1.end(); ++it)
	// 	std::cout << *(it) << " ";
	// std::cout << std::endl;

	try
	{
		std::cout << std::distance(vec.begin(), easyfind(vec, 4)) << std::endl;
		// std::cout << std::distance(vec.begin(), easyfind(vec, 5)) << std::endl;
		std::cout << std::distance(deque1.begin(), easyfind(deque1, 4)) << std::endl;
	}
	catch (const std::exception& e) 
	{
		std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}