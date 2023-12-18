#pragma once
#include <iostream>
#include "Form.hpp"
#include "AForm.hpp"

class Form; // 전방선언

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;

		// member function
		void setGrade(int number);
		
	public:
		// orthodox canonical form
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		// construtor overload
		Bureaucrat(std::string str, int number);

		// member function
		std::string	getName() const;
		int getGrade(void);
		void upGrade();
		void upGrade(int number);
		void downGrade();
		void downGrade(int number);

		// new member function in ex01 
		void signForm(Form &form);

		// new member function in ex02
		void executeForm(AForm const &form);

		// Exception class
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
};

std::ostream& operator<<(std::ostream &output, Bureaucrat &member);