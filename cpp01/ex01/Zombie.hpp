#pragma once
# include <iostream>
# include <sstream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	setName(std::string name);
		void	announce(void);
};

Zombie *zombieHorde(int n, std::string name);