#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:

		Form(const std::string& name, uint32_t sign_grade, uint32_t exec_grade);
		Form(const Form& other);
		~Form();

		Form&			operator=(const Form& other);

		std::string const&	getName() const;
		bool				getSigned() const;
		uint32_t			getSignGrade() const;
		uint32_t			getExecGrade() const;

		void				beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			const char*		what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char*		what() const throw();
		};

	private:

		const std::string	_name;
		bool				_signed;
		const uint32_t		_sign_grade;
		const uint32_t		_exec_grade;

};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif