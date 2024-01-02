#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac <= 2)
			throw PmergeMe::WrongInput();
		else
		{
			PmergeMe pm(ac, av);
			// pm.caseVector();
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}