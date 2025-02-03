#include "../../headers/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	// std::cout << "Source constructor" << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = nullptr;
}
MateriaSource::MateriaSource(const MateriaSource& other)
{
	// std::cout << "Source copy constructor" << std::endl;
	*this = other;
}
MateriaSource::~MateriaSource()
{
	// std::cout << "Source destructor" << std::endl;
	for (int i = 0; i < 4; i++)
		delete _materia[i];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	// std::cout << "Source copy assignment operator" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _materia[i];
			_materia[i] = (other._materia[i] ? other._materia[i]->clone() : nullptr);
		}
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_materia[i])
		{
			_materia[i] = m;
			return;
		}
	}
	// std::cout << "Materia slots full, new materia not learned" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++) 
	{
		if (_materia[i] && _materia[i]->getType() == type)
			return (_materia[i]->clone());
	}
	std::cout << "Unknown materia type: " << type << std::endl;
	return (nullptr);
}