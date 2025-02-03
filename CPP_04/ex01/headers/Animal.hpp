#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"
# include <iostream>
# include <string>

class Animal
{
	public:

		Animal();
		Animal(const Animal &other);
		virtual ~Animal();

		Animal	&operator=(const Animal &other);

		std::string		getType() const;
		virtual void	makeSound() const;
		virtual Brain*	pickBrain() const;

	protected:

		std::string	_type;

};

#endif