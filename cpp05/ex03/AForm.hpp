#pragma once
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat; // 전방선언

class AForm // 추상클래스로 만들어줘야 함.
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int exeGrade;
		void checkGrade(int grade);

	public:
		// orthodox canonical form
		AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		// constructor overload
		AForm(std::string name, int sign, int exec);

		// member function
		std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExeGrade() const;
		void beSigned(Bureaucrat &member);

		// new member function in ex02
		// 순수 가상함수로 제작
		virtual void execute(const Bureaucrat &executor) const = 0;

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

std::ostream& operator<<(std::ostream &output, AForm &form);