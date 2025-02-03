#include "../../headers/Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++) 
		_ideas[i] = "";
	std::cout << "Brain grown" << std::endl;
}
Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "Brain grown" << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain decayed" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

void		Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index <= 100)
		_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index <= 100)
		return (_ideas[index]);
	return ("*emptiness*");
}