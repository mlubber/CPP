#include "../../headers/Array.hpp"

template <typename T>
Array<T>::Array() : _data(nullptr), _size(0)
{
	std::cout << "Default constructor" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "Param constructor" << std::endl;
	_data = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	std::cout << "Copy constructor" << std::endl;
	_data = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Default destructor" << std::endl;
	delete[] _data;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size) 
		throw std::out_of_range("Index out of bounds");
	return (_data[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}
