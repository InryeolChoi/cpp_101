#include "FileChange.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "You've typed wrong number of parameters." << std::endl;
		return (0);
	}

	FileChange fc(av[1], av[2], av[3]);
	if (fc.check_param() == 1)
		return (1);
	fc.set_new_file();
	return (0);
}