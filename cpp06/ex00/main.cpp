#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw ScalarConverter::NotEnoughArgs();
		else
			ScalarConverter sc(av[1]);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}