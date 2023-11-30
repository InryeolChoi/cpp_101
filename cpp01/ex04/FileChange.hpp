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
		FileChange(std::string filename, std::string s1, std::string s2);
		~FileChange();
		int		check_param(void);
		void	set_new_file();
};