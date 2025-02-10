#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:

		AForm(const std::string& name, const std::string& target, uint32_t sign_grade, uint32_t exec_grade);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm&			operator=(const AForm& other);

		std::string const&	getName() const;
		std::string const&	getTarget() const;
		bool				getSigned() const;
		uint32_t			getSignGrade() const;
		uint32_t			getExecGrade() const;

		void				beSigned(Bureaucrat& bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception
		{
			const char*		what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char*		what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			const char*		what() const throw();
		};
	
	protected:

		virtual void		action() const = 0;

	private:

		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const uint32_t		_sign_grade;
		const uint32_t		_exec_grade;

};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif