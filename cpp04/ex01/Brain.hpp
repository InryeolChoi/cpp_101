#pragma once
#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain &obj);
		Brain &operator=(const Brain &obj);
		~Brain();

		void setidea(int i, std::string str);
		std::string getidea(int i);
};