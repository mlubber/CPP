#include "../headers/Array.hpp"

// int	main(void)
// {
// 	try
// 	{
// 		Array<int> arr;
// 		std::cout << "Empty array size: " << arr.size() << std::endl;

// 		Array<int> intArray(10);
// 		std::cout << "Int array size: " << intArray.size() << std::endl;

// 		for (unsigned int i = 0; i < intArray.size(); i++)
// 			intArray[i] = i * 42;

// 		std::cout << "Int array contents: " << std::endl;
// 		for (unsigned int i = 0; i < intArray.size(); i++)
// 			std::cout << intArray[i] << " ";
// 		std::cout << std::endl;

// 		Array<int> copyArray(intArray);
// 		std::cout << "Copied array size: " << copyArray.size() << std::endl;
// 		std::cout << "Set copy index [0] to 9" << std::endl;
// 		copyArray[0] = 9;
// 		std::cout << "Original array after modification: " << std::endl;
// 		for (unsigned int i = 0; i < intArray.size(); i++)
// 			std::cout << intArray[i] << " ";
// 		std::cout << std::endl;
// 		std::cout << "Copied array after modification: " << std::endl;
// 		for (unsigned int i = 0; i < copyArray.size(); i++)
// 			std::cout << copyArray[i] << " ";
// 		std::cout << std::endl;

// 		Array<int> assignedArray;
// 		assignedArray = copyArray;
// 		for (unsigned int i = 0; i < assignedArray.size(); i++)
// 			std::cout << assignedArray[i] << " ";
// 		std::cout << std::endl;

// 		std::cout << "Accessing out-of-bounds: " << arr[1] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return (0);
// }

// int	main(void)
// {
// 	try
// 	{
// 		Array<char> arr;
// 		std::cout << "Empty array size: " << arr.size() << std::endl;

// 		Array<char> charArray(10);
// 		std::cout << "Char array size: " << charArray.size() << std::endl;

// 		for (unsigned int i = 0; i < charArray.size(); i++)
// 			charArray[i] = i + 97;

// 		std::cout << "Char array contents: " << std::endl;
// 		for (unsigned int i = 0; i < charArray.size(); i++)
// 			std::cout << charArray[i] << " ";
// 		std::cout << std::endl;

// 		Array<char> copyArray(charArray);
// 		std::cout << "Copied array size: " << copyArray.size() << std::endl;
// 		std::cout << "Set copy index [0] to 'c'" << std::endl;
// 		copyArray[0] = 99;
// 		std::cout << "Original array after modification: " << std::endl;
// 		for (unsigned int i = 0; i < charArray.size(); i++)
// 			std::cout << charArray[i] << " ";
// 		std::cout << std::endl;
// 		std::cout << "Copied array after modification: " << std::endl;
// 		for (unsigned int i = 0; i < copyArray.size(); i++)
// 			std::cout << copyArray[i] << " ";
// 		std::cout << std::endl;

// 		Array<char> assignedArray;
// 		assignedArray = copyArray;
// 		for (unsigned int i = 0; i < assignedArray.size(); i++)
// 			std::cout << assignedArray[i] << " ";
// 		std::cout << std::endl;

// 		std::cout << "Accessing out-of-bounds: " << arr[1] << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return (0);
// }

int	main(void)
{
	try
	{
		Array<std::string> arr;
		std::cout << "Empty array size: " << arr.size() << std::endl;

		Array<std::string> strArray(5);
		std::cout << "String array size: " << strArray.size() << std::endl;

		strArray[0] = "Hello";
		strArray[1] = "World";
		strArray[2] = "This";
		strArray[3] = "Is";
		strArray[4] = "Me";

		std::cout << "Char array contents: " << std::endl;
		for (unsigned int i = 0; i < strArray.size(); i++)
			std::cout << strArray[i] << " ";
		std::cout << std::endl;

		Array<std::string> copyArray(strArray);
		std::cout << "Copied array size: " << copyArray.size() << std::endl;
		std::cout << "Set copy index [4] to \"C++\'" << std::endl;
		copyArray[4] = "C++";
		std::cout << "Original array after modification: " << std::endl;
		for (unsigned int i = 0; i < strArray.size(); i++)
			std::cout << strArray[i] << " ";
		std::cout << std::endl;
		std::cout << "Copied array after modification: " << std::endl;
		for (unsigned int i = 0; i < copyArray.size(); i++)
			std::cout << copyArray[i] << " ";
		std::cout << std::endl;

		Array<std::string> assignedArray;
		assignedArray = copyArray;
		for (unsigned int i = 0; i < assignedArray.size(); i++)
			std::cout << assignedArray[i] << " ";
		std::cout << std::endl;

		std::cout << "Accessing out-of-bounds: " << arr[1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}