#include "../headers/Serializer.hpp"

int	main(void)
{
	Data		data;
	Data*		restoredData;
	uintptr_t	raw;

	data.number = 42;
	data.text = "Hello, world!";
	raw = Serializer::serialize(&data);
	restoredData = Serializer::deserialize(raw);

	std::cout	<< "Original Data address:		" << &data
				<< "\nSerialized uintptr_t:		" << raw
				<< "\nDeserialized Data address:	" << restoredData << std::endl;

	if (restoredData == &data) 
	{
		std::cout	<< "\nRestored data:\nnumber:	" << restoredData->number
					<< "\ntext:	" << restoredData->text << std::endl;
	} 
	else
		std::cout << "Error: address doesn't match" << std::endl;
	return (0);
}