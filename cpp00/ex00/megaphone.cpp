#include <iostream>
#include <cstring>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		std::string str;
		for (int i = 1; i < ac; i++)
		{
			str.assign(av[i], strlen(av[i]));
			for (int x = 0; x < str.size(); x++)
				str[x] = toupper(str[x]);
			std::cout << str;
		}
		std::cout << std::endl;
	}
}