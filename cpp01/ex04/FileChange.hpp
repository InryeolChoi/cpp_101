#pragma once
#include <iostream>
#include <fstream>

class FileChange
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;
		std::ifstream infile;
		std::ofstream outfile;
		std::string line;

	public:
		FileChange();
		FileChange(char *filename, char *s1, char *s2);
		~FileChange();
		int		open(void);
		void	set_new();
};