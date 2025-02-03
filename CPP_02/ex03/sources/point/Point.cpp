#include "../../headers/Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// std::cout << "Float constructor called" << std::endl;
}

// Copy constructor
Point::Point(const Point& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

// Copy assignment operator overload
Point& Point::operator=(const Point& other)
{
	// std::cout << "Point copy assignment operator called" << std::endl;
	// Since x and y are const, we cannot reassign them
	(void)other; // Suppress unused warning
	return (*this);
}

// Memberfunctions

Fixed Point::get_x() const
{
	return (_x);
}

Fixed Point::get_y() const
{
	return (_y);
}