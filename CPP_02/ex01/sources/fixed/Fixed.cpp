#include "../../headers/Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Overload constructor for an integer paramater
Fixed::Fixed(const int int_value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = int_value << _pointbits;
}

// Overload constructor for a floating-point number parameter
Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(float_value * (1 << _pointbits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator overload
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Memberfunctions

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(_value) / (1 << _pointbits));
}

int Fixed::toInt(void) const
{
	return (_value >> _pointbits);
}

// Overload function for the insertion operator
std::ostream &operator<<(std::ostream &outputstream, const Fixed &object)
{
	outputstream << object.toFloat();
	return (outputstream);
}
