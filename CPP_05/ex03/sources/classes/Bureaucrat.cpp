#include "../../headers/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy assignment operator" << std::endl;
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

std::string const&	Bureaucrat::getName() const
{
	return(_name);
}

uint32_t	Bureaucrat::getGrade() const
{
	return(_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
	std::cout << _name << " got a promotion!" << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
	std::cout << _name << " was demoted" << std::endl;
}
void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch	(const std::exception& e)
	{
		std::cout	<< _name << " couldn't sign "
					<< form.getName() << " because "
					<< e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try 
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	} 
	catch (const std::exception& e) 
	{
		std::cerr	<< getName() << " couldn't execute "
					<< form.getName() << " because "
					<< e.what() << std::endl;
	}
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too low!");
}

std::ostream& operator<<(std::ostream& outstream, const Bureaucrat& bureaucrat)
{
	outstream	<< "Bureaucrat: \"" << bureaucrat.getName()
				<< "\" [Grade: " << bureaucrat.getGrade()
				<< "]";

	return (outstream);
}
