#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm();
		std::string target;

	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();

		// member function
		std::string getTarget();

		// override
		void execute(Bureaucrat const & executor);

		// Exception
		class OpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};