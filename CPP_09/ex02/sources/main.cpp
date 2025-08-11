#include "../headers/PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try
	{
		std::vector<int>	v_list;
		std::deque<int>		d_list;
		double				v_time;
		double				d_time;

		v_time = funcTime([&]() { parseInput(argc, argv, v_list); });
		d_time = funcTime([&]() { parseInput(argc, argv, d_list); });

		std::cout << "Before:	";
		printList(v_list, 5);

		v_time += funcTime([&]() { vecFordJohnson(v_list); });
		d_time += funcTime([&]() { deqFordJohnson(d_list); });
		
		// v_time += funcTime([&]() { vectorSort(v_list); });
		// d_time += funcTime([&]() { dequeSort(d_list); });

		// v_time += funcTime([&]() { mergeInsertSort(v_list); });
		// d_time += funcTime([&]() { mergeInsertSort(d_list); });

		std::cout << "After:	";
		printList(v_list, 5);

		std::cout	<< "Time to process a range of "
					<< v_list.size() << " elements with std::[vec] : "
					<< setFixedPrecision(10, v_time) << " s" << std::endl;

		std::cout	<< "Time to process a range of "
					<< d_list.size() << " elements with std::[deq] : "
					<< setFixedPrecision(10, d_time) << " s" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (0);
}