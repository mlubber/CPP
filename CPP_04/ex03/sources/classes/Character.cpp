#include "../../headers/Character.hpp"

MateriaNode::MateriaNode(AMateria* mat) : materia(mat), next(nullptr)
{
	std::cout << "Unequipped materia: " << materia->getType() << std::endl;
}

Character::Character() : _name("no_name"), _unequipped(nullptr)
{
	// std::cout << "Character constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_slot[i] = nullptr;
}
Character::Character(std::string const& name) : _name(name), _unequipped(nullptr)
{
	// std::cout << "Character parameter constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_slot[i] = nullptr;
}
Character::Character(const Character& other)
{
	// std::cout << "Character copy constructor" << std::endl;
	*this = other;
}
Character::~Character()
{
	// std::cout << "Character destructor" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete _slot[i];
		_slot[i] = nullptr;
	}
	clearUnequip();
}

Character& Character::operator=(const Character& other)
{
	// std::cout << "Character copy assignment operator" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			delete _slot[i];
			_slot[i] = (other._slot[i] ? other._slot[i]->clone() : nullptr);
		}

	}
	return (*this);
}

std::string const& 	Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_slot[i])
		{
			_slot[i] = m;
			// std::cout << m->getType() << " equipped in slot " << i << std::endl;
			return ;
		}
	}
	// std::cout << "Inventory slots full, item not equipped" << std::endl;
}

void	Character::unequip(int idx)
{
	if (_slot[idx] && idx >= 0 && idx < 4)
	{
		MateriaNode* newNode = new MateriaNode(_slot[idx]);
		newNode->next = _unequipped;
		_unequipped = newNode;
		_slot[idx] = nullptr;
		return ;
	}
	// std::cout << "No item found in inventory slot" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (_slot[idx] && idx >= 0 && idx < 4)
	{
		_slot[idx]->use(target);
		return ;
	}
	std::cout << "* No item in inventory slot *" << std::endl;
}

void	Character::clearUnequip(void)
{
	MateriaNode* current = _unequipped;
	while (current)
	{
		MateriaNode* temp = current;
		current = current->next;
		delete temp->materia;
		delete temp;
	}
	_unequipped = nullptr;
}
