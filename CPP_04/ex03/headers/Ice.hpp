#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:

		Ice();
		Ice(const Ice& other);
		~Ice();

		Ice&		operator=(const Ice& other);

		AMateria*	clone() const override;
		void		use(ICharacter& target) override;

	protected:

		std::string	_type;

};

#endif