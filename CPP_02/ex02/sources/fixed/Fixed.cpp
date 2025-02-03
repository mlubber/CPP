#include "../../headers/Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

// Overload constructor for an integer paramater
Fixed::Fixed(const int int_value)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = int_value << _pointbits;
}

// Overload constructor for a floating-point number parameter
Fixed::Fixed(const float float_value)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(float_value * (1 << _pointbits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}


// Increment/decrement operators

Fixed	&Fixed::operator++()
{
	this->_value += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value += 1;
	return (temp);
}

Fixed	&Fixed::operator--()
{
	this->_value -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value -= 1;
	return (temp);
}


// Comparison operators


bool	Fixed::operator>(const Fixed &other) const
{
	// std::cout << "Greater than operator called" << std::endl;
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed &other) const
{
	// std::cout << "Less than operator called" << std::endl;
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	// std::cout << "Greater or equals operator called" << std::endl;
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	// std::cout << "Less or equals operator called" << std::endl;
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other) const
{
	// std::cout << "Equals operator called" << std::endl;
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	// std::cout << "Does not equal operator called" << std::endl;
	return (this->_value != other._value);
}


// Arithmetic operators


Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	// std::cout << "Addition operator called" << std::endl;
	result._value = this->_value + other._value;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	// std::cout << "Subtraction operator called" << std::endl;
	result._value = this->_value - other._value;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result;

	// std::cout << "Multiplication operator called" << std::endl;
	result._value = (this->_value * other._value) >> _pointbits;
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result;

	// std::cout << "Division operator called" << std::endl;
	if (other._value == 0)
		std::cerr << "Runtime error: Division by zero" << std::endl;
	result._value = (this->_value << _pointbits) / other._value;
	return (result);
}


// Memberfunctions


int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

Fixed	&Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed	&Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

// Overload function for the insertion operator
std::ostream &operator<<(std::ostream &outputstream, const Fixed &object)
{
	outputstream << object.toFloat();
	return (outputstream);
}
