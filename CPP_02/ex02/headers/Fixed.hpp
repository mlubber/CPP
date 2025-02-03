#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:

		Fixed();
		Fixed(const int int_value);
		Fixed(const float float_value);
		Fixed(const Fixed &other);
		~Fixed();
		
		Fixed		&operator=(const Fixed &other);

		Fixed 		&operator++();
		Fixed 		operator++(int);
		Fixed 		&operator--();
		Fixed 		operator--(int);

		bool		operator>(const Fixed &other) const;
		bool		operator<(const Fixed &other) const;
		bool		operator>=(const Fixed &other) const;
		bool		operator<=(const Fixed &other) const;
		bool		operator==(const Fixed &other) const;
		bool		operator!=(const Fixed &other) const;

		Fixed		operator+(const Fixed &other) const;
		Fixed		operator-(const Fixed &other) const;
		Fixed		operator*(const Fixed &other) const;
		Fixed		operator/(const Fixed &other) const;

		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float 		toFloat(void) const;
		int			toInt(void) const;

		static Fixed		&min(Fixed& a, Fixed& b);
		static const Fixed	&min(const Fixed& a, const Fixed& b);
		static Fixed		&max(Fixed& a, Fixed& b);
		static const Fixed	&max(const Fixed& a, const Fixed& b);

		friend std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

	private:
	
		static const int	_pointbits = 8;
		int					_value;
		
};

#endif