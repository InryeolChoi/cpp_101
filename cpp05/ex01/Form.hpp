#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; // 전방선언

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int exeGrade;
		void checkGrade(int grade);

	public:
		// orthodox canonical form
		Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		// constructor overload
		Form(std::string name, int sign, int exec);

		// member function
		std::string getName() const;
		bool getIsSigned();
		int getSignGrade() const;
		int getExeGrade() const;
		void beSigned(Bureaucrat &member);

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
		class AlreadySignedException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &output, Form &form);