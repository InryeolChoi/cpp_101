#pragma once
#include <iostream>

class Bureaucrat
{
	private:
		std::string const name;
		int	grade;

	public:
		// orthodox canonical form
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		// member function
		std::string	getName() const;
		void setGrade(int num);
		int getGrade(void);
		void upGrade(int num);
		void downGrade(int num);
};

std::ostream& operator<<(std::string name, int grade);