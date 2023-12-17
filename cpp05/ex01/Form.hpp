#pragma once
#include <iostream>


class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int grade_sign;
		const int grade_exe;

	public:
		// orthodox canonical form
		Form();
		Form();
		~Form();

		// exception class
		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
}
