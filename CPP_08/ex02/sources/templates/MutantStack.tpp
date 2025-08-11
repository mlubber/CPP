#include "../../headers/MutantStack.hpp"

template <typename T, typename Container>
const T&	MutantStack<T, Container>::operator[](size_t index)
{
	if (index >= this->c.size())
		throw std::out_of_range("Index out of bounds");
	return(this->c[index]);
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin()
{
	return(this->c.begin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end()
{
	return(this->c.end());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::cbegin() const
{
	return(this->c.cbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::cend() const
{
	return(this->c.cend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin()
{
	return(this->c.rbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend()
{
	return(this->c.rend());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::crbegin() const
{
	return(this->c.crbegin());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::crend() const
{
	return(this->c.crend());
}
