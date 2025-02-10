#include "../../headers/Form.hpp"

Form::Form(const std::string& name, uint32_t sign_grade, uint32_t exec_grade) : 
	_name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "File default constructor" << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) :
	_name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	std::cout << "File copy constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "File destructor" << std::endl;
}

Form&			Form::operator=(const Form& other)
{
	std::cout << "File copy assignment operator" << std::endl;
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

std::string const&	Form::getName() const
{
	return (_name);
}

bool				Form::getSigned() const
{
	return (_signed);
}

uint32_t			Form::getSignGrade() const
{
	return (_sign_grade);
}

uint32_t			Form::getExecGrade() const
{
	return (_exec_grade);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (_signed)
		throw std::logic_error("form is already signed!");
	if (bureaucrat.getGrade() > _sign_grade)
		throw GradeTooHighException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("form grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("form grade too low!");
}

std::ostream& operator<<(std::ostream& outstream, const Form& form)
{
	outstream	<< "Form: \"" << form.getName()
				<< "\" [Status: " << (form.getSigned() ? "Signed" : "Not Signed")
				<< ", Grade to sign: " << form.getSignGrade()
				<< ", Grade to execute: " << form.getExecGrade() << "]";
	return (outstream);
}