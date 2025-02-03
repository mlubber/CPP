#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:

		Cat();
		Cat(const Cat &other);
		~Cat();

		Cat	&operator=(const Cat &other);

		void		makeSound() const override;
		Brain		*pickBrain() const override;

	private:

		Brain *_brain;

};

#endif