#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

struct MateriaNode
{
	AMateria* materia;
	MateriaNode* next;

	MateriaNode(AMateria* mat);
};

class Character : public ICharacter
{
	public:

		Character();
		Character(std::string const& name);
		Character(const Character& other);
		virtual ~Character();

		Character&			operator=(const Character& other);

		std::string const& 	getName() const override;
		void				equip(AMateria* m) override;
		void				unequip(int idx) override;
		void				use(int idx, ICharacter& target) override;
		void				clearUnequip();

	private:

		std::string			_name;
		AMateria*			_slot[4];
		MateriaNode*		_unequipped;
};

#endif