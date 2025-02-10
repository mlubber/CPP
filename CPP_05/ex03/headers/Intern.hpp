#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class AForm;

class Intern
{
	public:

		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern&	operator=(const Intern& other);

		AForm* makeForm(const std::string& form_name, const std::string& target);

		class FormNotFoundException : public std::exception
		{
			const char*		what() const throw();
		};

	private:

		static AForm* createShrubberyForm(const std::string& target);
		static AForm* createRobotomyForm(const std::string& target);
		static AForm* createPresidentialForm(const std::string& target);

};

#endif