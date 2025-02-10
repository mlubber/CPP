#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
	public:

		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat&			operator=(const Bureaucrat& other);
		
		std::string const&	getName() const;
		uint32_t			getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

		class GradeTooHighException : public std::exception
		{
			const char*		what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			const char*		what() const throw();
		};

	protected:

		const std::string	_name;
		uint32_t			_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif