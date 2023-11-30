#include "FileChange.hpp"

FileChange::FileChange() {}

FileChange::FileChange(std::string filename, std::string s1, std::string s2)
: filename(filename), s1(s1), s2(s2),
	infile(filename.c_str(), std::ios::in),
	outfile((filename + ".replace").c_str(), std::ios::out)
{}

int FileChange::check_param()
{
	if (!infile.is_open() || !outfile.is_open())
	{
		std::cerr << "file doesn't open well" << std::endl;
		return (1);
	}
	if (s1 == "")
	{
		std::cout << "please type with the characters" << std::endl;
		return (1);
	}
	return (0);
}

void FileChange::set_new_file()
{
	while (std::getline(infile, line))
	{
		size_t pos = line.find(s1); // s1의 시작 위치를 찾는다.
		while (pos != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos = line.find(pos + s2.length()); // 옛날 s1의 위치 + s2의 길이만큼 이동
		}
		outfile << line << std::endl;
	}
}

FileChange::~FileChange()
{
	infile.close();
	outfile.close();
}