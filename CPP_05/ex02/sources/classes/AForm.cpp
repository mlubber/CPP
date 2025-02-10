#include "../../headers/AForm.hpp"

AForm::AForm(const std::string& name, const std::string& target, uint32_t sign_grade, uint32_t exec_grade) : 
	_name(name), _target(target), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "File default constructor" << std::endl;
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) :
	_name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	std::cout << "File copy constructor" << std::endl;
}

AForm::~AForm()
{
	std::cout << "File destructor" << std::endl;
}

AForm&			AForm::operator=(const AForm& other)
{
	std::cout << "File copy assignment operator" << std::endl;
	if (this != &other)
	{
		_signed = other._signed;
	}
	return (*this);
}

std::string const&	AForm::getName() const
{
	return (_name);
}

std::string const&	AForm::getTarget() const
{
	return (_target);
}

bool				AForm::getSigned() const
{
	return (_signed);
}

uint32_t			AForm::getSignGrade() const
{
	return (_sign_grade);
}

uint32_t			AForm::getExecGrade() const
{
	return (_exec_grade);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (_signed)
		throw std::logic_error("form is already signed!");
	if (bureaucrat.getGrade() > _sign_grade)
		throw GradeTooHighException();
	_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _exec_grade)
		throw GradeTooHighException();
	action();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("form grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("form grade too low!");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("form is not signed!");
}

std::ostream& operator<<(std::ostream& outstream, const AForm& form)
{
	outstream	<< "Form: \"" << form.getName()
				<< "\" [Status: " << (form.getSigned() ? "signed" : "not signed")
				<< ", sign grade: " << form.getSignGrade()
				<< ", exec grade: " << form.getExecGrade() << "]";
	return (outstream);
}