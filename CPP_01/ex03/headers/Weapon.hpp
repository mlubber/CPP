#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon 
{
	public:

		Weapon();
		Weapon(const std::string& initialtype);
		~Weapon();

		const std::string&	getType() const;
		void				setType(const std::string& newtype);

	private:

		std::string _type;

};

#endif