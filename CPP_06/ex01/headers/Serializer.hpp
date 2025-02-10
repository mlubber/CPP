#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

struct Data
{
	int			number;
	std::string	text;
};

class Serializer
{
	public:

		static uintptr_t	serialize(Data* ptr);
		static Data* 		deserialize(uintptr_t raw);

	private:

		Serializer();
		Serializer(const Serializer& other);
		~Serializer();

		Serializer&	operator=(const Serializer& other);	
};

#endif