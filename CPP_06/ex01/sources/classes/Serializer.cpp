#include "../../headers/Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Default constructor" << std::endl;
}
Serializer::Serializer(const Serializer& other)
{
	std::cout << "Copy constructor" << std::endl;
	(void)other;
}
Serializer::~Serializer()
{
	std::cout << "Default destructor" << std::endl;
}

Serializer&	Serializer::operator=(const Serializer& other)
{
	std::cout << "Copy assignment operator" << std::endl;
	(void)other;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data* 		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}