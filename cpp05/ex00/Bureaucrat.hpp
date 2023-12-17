#pragma once
#include <iostream>

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