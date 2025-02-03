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
		virtual void	makeSound() const = 0;
		virtual Brain*	pickBrain() const = 0;

	protected:

		std::string	_type;

};

#endif