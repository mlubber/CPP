#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:

		Fixed();
		Fixed(const Fixed &other);
		~Fixed();

		Fixed &operator=(const Fixed &other);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
	
		static const int	_pointbits = 8;
		int					_value;
		
};

#endif