template <typename T>
void easyfind(T& elements, int num)
{	
	typename T::iterator it = std::find(elements.begin(), elements.end(), num);
	if (it != elements.end())
		std::cout << "Element found: " << *it << std::endl;
	else
		throw std::runtime_error("Element not found");
}