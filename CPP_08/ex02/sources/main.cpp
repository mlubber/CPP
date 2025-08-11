#include "../headers/MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}

// int main (void)
// {
// 	std::srand(std::time(0));
// 	try
// 	{
// 		MutantStack<int> mstack;
// 		MutantStack<int> nstack;
// 		std::string empty;
// 		size_t stack_size = 5;


// 		std::cout << "\nStack 1: \n";
// 		empty = mstack.empty() ? "yes" : "no";
// 		std::cout << "empty: " << empty << std::endl;

// 		for (size_t i = 0; i < stack_size; ++i)
// 			mstack.push(std::rand() % 100);
// 		mstack.emplace(42);

// 		for (size_t i = 0; i < mstack.size(); ++i)
// 			std::cout << mstack[i] << " ";
// 		empty = mstack.empty() ? "yes" : "no";
// 		std::cout	<< "\nempty: " 
// 					<< empty
// 					<< "\nSize: " 
// 					<< mstack.size() << "\n" 
// 					<< std::endl;

// 		std::cout	<< "Stack 1 top: " << mstack.top()
// 					<< "\n*pop*" << std::endl;
// 		mstack.pop();
// 		std::cout << "Stack 1 top: " << mstack.top() << std::endl;
// 		for (size_t i = 0; i < mstack.size(); ++i)
// 			std::cout << mstack[i] << " ";
// 		std::cout	<< "\nSize: " 
// 					<< mstack.size() << "\n" 
// 					<< std::endl;


// 		std::cout << "\nStack 2: \n";
// 		empty = nstack.empty() ? "yes" : "no";
// 		std::cout << "empty: " << empty << std::endl;

// 		for (size_t i = 0; i < stack_size; ++i)
// 			nstack.push(std::rand() % 100);
// 		nstack.emplace(42);

// 		for (size_t i = 0; i < nstack.size(); ++i)
// 			std::cout << nstack[i] << " ";
// 		empty = nstack.empty() ? "yes" : "no";
// 		std::cout	<< "\nempty: " 
// 					<< empty
// 					<< "\nSize: " 
// 					<< nstack.size() << "\n" 
// 					<< std::endl;

// 		std::cout	<< "Stack 2 top: " << nstack.top()
// 					<< "\n*pop*" << std::endl;
// 		nstack.pop();
// 		std::cout << "Stack 2 top: " << nstack.top() << std::endl;
// 		for (size_t i = 0; i < nstack.size(); ++i)
// 			std::cout << nstack[i] << " ";
// 		std::cout	<< "\nSize: " 
// 					<< nstack.size() << "\n\n" 
// 					<< std::endl;

// 		std::cout << "Iterator:" << std::endl;

// 		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
// 			std::cout << *it << " ";
// 		std::cout	<< "(Stack 1)"
// 					<< std::endl;
// 		for (MutantStack<int>::iterator it = nstack.begin(); it != nstack.end(); ++it)
// 			std::cout << *it << " ";
// 		std::cout	<< "(Stack 2)"
// 					<< std::endl;

// 		mstack.swap(nstack);
// 		std::cout << "*swap stacks*" << std::endl;

// 		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
// 			std::cout << *it << " ";
// 		std::cout	<< "(Stack 1)"
// 					<< std::endl;
// 		for (MutantStack<int>::iterator it = nstack.begin(); it != nstack.end(); ++it)
// 			std::cout << *it << " ";
// 		std::cout	<< "(Stack 2)"
// 					<< std::endl;

// 		std::cout << "\nReverse Iterator:" << std::endl;

// 		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
// 			std::cout << *it << " ";
// 		std::cout	<< "(Stack 1)"
// 					<< std::endl;
// 		for (MutantStack<int>::reverse_iterator it = nstack.rbegin(); it != nstack.rend(); ++it)
// 			std::cout << *it << " ";
// 		std::cout	<< "(Stack 2)"
// 					<< std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	return (0);
// }