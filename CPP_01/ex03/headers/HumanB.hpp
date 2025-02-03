#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB 
{
	public:

		HumanB(std::string name);
		~HumanB();

		void	setWeapon(Weapon& new_weapon);
		void	attack();

	private:

		std::string	_name;
		Weapon		*_weapon;

};

#endif