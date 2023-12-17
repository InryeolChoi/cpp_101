#include "Form.hpp"

// orthodox canonical form
Form::Form() : name("_form"), isSigned(false), signGrade(1), exeGrade(1)
{
	std::cout << "The form " <<  name << " is initialized" << std::endl;
}

Form::Form(const Form &other)
	: name(other.name), isSigned(false), 
		signGrade(other.signGrade), 
		exeGrade(other.exeGrade)
{}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return (*this);
}

Form::~Form()
{}

// constructor overload
Form::Form(std::string name, int sign, int exec)
	: name(name), isSigned(false), signGrade(sign), exeGrade(exec)
{
	checkGrade(sign);
	checkGrade(exec);
	std::cout << "The form " <<  name << " is initialized" << std::endl;
}

// member function
void Form::checkGrade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 0)
		throw GradeTooHighException();
}

std::string Form::getName() const
{
	return name;
}

int Form::getSignGrade() const
{
	return signGrade;
}

int Form::getExeGrade() const
{
	return exeGrade;
}

bool Form::getIsSigned()
{
	return isSigned;
}

void Form::beSigned(Bureaucrat &member)
{
	if (isSigned == true)
		throw AlreadySignedException();
	
	// "폼의 등급 < 관료의 등급" 이면 폼이 더 높다.
	// 따라서 싸인이 불가. (예외처리)
	if (signGrade < member.getGrade())
		throw GradeTooLowException();
	isSigned = true;
}

// exception
const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("The form has been signed already");
}

// overloading operator <<
std::ostream& operator<<(std::ostream &output, Form &form)
{
	output << form.getName() << ", ";
	if (form.getIsSigned())
		output << "signed" << ", ";
	else
		output << "not signed" << ", ";
	output << form.getSignGrade() << " signGrade, ";
	output << form.getExeGrade() << " exeGrade" << std::endl;
	return (output);
}