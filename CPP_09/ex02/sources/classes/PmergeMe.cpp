#include "../../headers/PmergeMe.hpp"

void	printList(std::vector<int>& list, size_t size)
{
	if (list.size() <= size)
	{
		for (int n : list)
			std::cout << n << " ";
	}
	else
	{
		for (size_t i = 0; i < size; ++i)
			std::cout << list[i] << " ";
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

std::string	setFixedPrecision(int prec, double num)
{
	std::ostringstream out;
	out << std::fixed << std::setprecision(prec) << num;
	std::string result = out.str();

	result.erase(result.find_last_not_of('0') + 1);
	if (result.back() == '.')
        result.pop_back();
	return (result);
}

std::vector<size_t> jacobsthalSequence(size_t n)
{
	std::vector<size_t> seq;
	if (n == 0) 
		return (seq);
	seq.push_back(0);
	if (n == 1) 
		return (seq);
	seq.push_back(1);
	size_t last = 0;
	size_t curr = 1;
	while (seq.size() < n)
	{
		size_t next = (2 * last) + curr;
		seq.push_back(next);
		last = curr;
		curr = next;
	}
	// Remove values >= n
	while (!seq.empty() && seq.back() >= n)
		seq.pop_back();
	return (seq);
}

void	vectorSort(std::vector<int>& list)
{
	if (list.size() <= 1)
		return;

	std::vector<int> A_list;
	std::vector<int> B_list;

	for (std::vector<int>::iterator it = list.begin(); it != list.end(); ++it)
    {
		std::vector<int>::iterator next = it;
		++next;
		if (next == list.end())
			break;
		if (*it < *next)
		{
			A_list.push_back(*it);
			B_list.push_back(*next);
		}
    	else
		{
			B_list.push_back(*it);
			A_list.push_back(*next);
		}
		it = next;
	}

	if (list.size() % 2 != 0)
		A_list.push_back(list.back());

	vectorSort(A_list);

	std::vector<int>::iterator insert_pos;

	// Linear insert
	// for(size_t i = 0; i < B_list.size(); ++i)
	// {
	// 	insert_pos = std::lower_bound(A_list.begin(), A_list.end(), B_list[i]);
	// 	A_list.insert(insert_pos, B_list[i]);
	// }

	// Jacobsthal insert
	std::vector<bool> inserted(B_list.size(), false);
	std::vector<size_t> insert_order = jacobsthalSequence(B_list.size());
	for (size_t i = 0; i < insert_order.size(); ++i) 
	{
		size_t index = insert_order[i];
		if (!inserted[index])
		{
			insert_pos = std::lower_bound(A_list.begin(), A_list.end(), B_list[index]);
			A_list.insert(insert_pos, B_list[index]);
			inserted[index] = true;
		}
	}
	for (size_t i = 0; i < B_list.size(); ++i)
	{
		if (!inserted[i])
		{
			insert_pos = std::lower_bound(A_list.begin(), A_list.end(), B_list[i]);
			A_list.insert(insert_pos, B_list[i]);
			inserted[i] = true;
		}
	}

	list = A_list;
}

void dequeSort(std::deque<int>& list)
{
	if (list.size() <= 1)
		return;

	std::deque<int> A_list;
	std::deque<int> B_list;

	for (std::deque<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		std::deque<int>::iterator next = it;
		++next;
		if (next == list.end())
			break;
		if (*it < *next)
		{
			A_list.push_back(*it);
			B_list.push_back(*next);
		}
		else
		{
			B_list.push_back(*it);
			A_list.push_back(*next);
		}
		it = next;
	}

	if (list.size() % 2 != 0)
		A_list.push_back(list.back());

	dequeSort(A_list); // Recursive call

	// std::vector<int> T_list(A_list.begin(), A_list.end()); // Temp store of deque in vector for sorting
	// std::vector<int>::iterator insert_pos;

	std::deque<int>::iterator insert_pos;

	// Linear insert
	// for(size_t i = 0; i < B_list.size(); ++i)
	// {
	// 	insert_pos = std::lower_bound(A_list.begin(), A_list.end(), B_list[i]);
	// 	A_list.insert(insert_pos, B_list[i]);
	// }

	// Jacobsthal insert
	std::vector<bool> inserted(B_list.size(), false);
	std::vector<size_t> insert_order = jacobsthalSequence(B_list.size());

	for (size_t i = 0; i < insert_order.size(); ++i)
	{
		size_t index = insert_order[i];
		if (!inserted[index])
		{
			insert_pos = std::lower_bound(A_list.begin(), A_list.end(), B_list[index]);
			A_list.insert(insert_pos, B_list[index]);
			inserted[index] = true;
		}
	}
	for (size_t i = 0; i < B_list.size(); ++i)
	{
		if (!inserted[i])
		{
			insert_pos = std::lower_bound(A_list.begin(), A_list.end(), B_list[i]);
			A_list.insert(insert_pos, B_list[i]);
			inserted[i] = true;
		}
	}
	// list.assign(T_list.begin(), T_list.end());
	list = A_list;
}

void vecFordJohnson(std::vector<int>& list)
{
	if (list.size() <= 1)
		return;
	
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> large;
	std::vector<int> small;

	// Step 1: Make sorted pairs (a, b) where a < b
	for (std::size_t i = 0; i + 1 < list.size(); i += 2)
	{
		int a = list[i];
		int b = list[i + 1];
		if (a > b)
			std::swap(a, b);
		large.push_back(b);
		small.push_back(a);
		pairs.push_back(std::make_pair(a, b));
	}

	// Step 2: If list has an odd element, add it to small
	if (list.size() % 2 != 0)
		small.push_back(list[list.size() - 1]);
	
	// Step 3: Call the function recursivly
	vecFordJohnson(large);

	// Step 4: Link large values to their indexes in `large`
	std::unordered_map<int, size_t> link_map;
	for (size_t i = 0; i < large.size(); ++i)
		link_map[large[i]] = i;

	// Step 5: Initialize position vector (pos[i] = current index of original large[i])
	std::vector<size_t> pos(large.size());
	for (size_t i = 0; i < large.size(); ++i)
		pos[i] = i;

	// Step 6: Jacobsthal insertion of small into large
	std::vector<bool> inserted(small.size(), false);
	std::vector<size_t> insert_order = jacobsthalSequence(small.size());

	std::vector<int>::iterator insert_pos;
	
	for (std::size_t i = 0; i < insert_order.size(); ++i)
	{
		size_t idx = insert_order[i];

		if (idx >= small.size() || inserted[idx])
			continue;

		size_t bound_index = large.size(); // default to end if no bound

		// Determine bound index from pos vector if pair exists
		if (idx < pairs.size())
			bound_index = pos[link_map[pairs[idx].second]];

		std::vector<int>::iterator bound_end = large.begin() + bound_index;
		insert_pos = std::upper_bound(large.begin(), bound_end, small[idx]);

		size_t insert_idx = insert_pos - large.begin();
		large.insert(insert_pos, small[idx]);
		inserted[idx] = true;

		// Update pos vector: increment indexes >= insert_idx to track shifting
		for (size_t j = 0; j < pos.size(); ++j)
		{
			if (pos[j] >= insert_idx)
				pos[j] = pos[j] + 1;
		}
	}

	// Step 7: Insert remaining small values not inserted above
	for (size_t i = 0; i < small.size(); ++i)
	{
		if (inserted[i])
			continue;

		size_t bound_index = large.size();

		if (i < pairs.size())
			bound_index = pos[link_map[pairs[i].second]];

		std::vector<int>::iterator bound_end = large.begin() + bound_index;
		insert_pos = std::upper_bound(large.begin(), bound_end, small[i]);

		size_t insert_idx = insert_pos - large.begin();
		large.insert(insert_pos, small[i]);
		inserted[i] = true;

		for (size_t j = 0; j < pos.size(); ++j)
		{
			if (pos[j] >= insert_idx)
				pos[j] = pos[j] + 1;
		}
	}

	// Step 8: Replace original list with sorted result
	list = large;
}

void deqFordJohnson(std::deque<int>& list)
{
	if (list.size() <= 1)
		return;
	
	std::vector<std::pair<int, int> > pairs;
	std::deque<int> large;
	std::deque<int> small;

	// Step 1: Make sorted pairs (a, b) where a < b
	for (std::size_t i = 0; i + 1 < list.size(); i += 2)
	{
		int a = list[i];
		int b = list[i + 1];
		if (a > b)
			std::swap(a, b);
		large.push_back(b);
		small.push_back(a);
		pairs.push_back(std::make_pair(a, b));
	}

	// Step 2: If list has an odd element, add it to small
	if (list.size() % 2 != 0)
		small.push_back(list[list.size() - 1]);
	
	// Step 3: Call the function recursivly
	deqFordJohnson(large);

	// Step 4: Link large values to their original indexes in `large`
	std::unordered_map<int, size_t> link_map;
	for (size_t i = 0; i < large.size(); ++i)
		link_map[large[i]] = i;

	// Step 5: Initialize position vector (pos[i] = current index of original large[i])
	std::vector<size_t> pos(large.size());
	for (size_t i = 0; i < large.size(); ++i)
		pos[i] = i;

	// Step 6: Jacobsthal insertion of small into large
	std::vector<bool> inserted(small.size(), false);
	std::vector<size_t> insert_order = jacobsthalSequence(small.size());

	std::deque<int>::iterator insert_pos;
	
	for (std::size_t i = 0; i < insert_order.size(); ++i)
	{
		size_t idx = insert_order[i];

		if (idx >= small.size() || inserted[idx])
			continue;

		size_t bound_index = large.size(); // default to end if no bound

		// Determine bound index from pos vector if pair exists
		if (idx < pairs.size())
			bound_index = pos[link_map[pairs[idx].second]];

		std::deque<int>::iterator bound_end = large.begin() + bound_index;
		insert_pos = std::upper_bound(large.begin(), bound_end, small[idx]);

		size_t insert_idx = insert_pos - large.begin();
		large.insert(insert_pos, small[idx]);
		inserted[idx] = true;

		// Update pos vector: increment indexes >= insert_idx to track shifting
		for (size_t j = 0; j < pos.size(); ++j)
		{
			if (pos[j] >= insert_idx)
				pos[j] = pos[j] + 1;
		}
	}

	// Step 7: Insert remaining small values not inserted above
	for (size_t i = 0; i < small.size(); ++i)
	{
		if (inserted[i])
			continue;

		size_t bound_index = large.size();

		if (i < pairs.size())
			bound_index = pos[link_map[pairs[i].second]];

		std::deque<int>::iterator bound_end = large.begin() + bound_index;
		insert_pos = std::upper_bound(large.begin(), bound_end, small[i]);

		size_t insert_idx = insert_pos - large.begin();
		large.insert(insert_pos, small[i]);
		inserted[i] = true;

		for (size_t j = 0; j < pos.size(); ++j)
		{
			if (pos[j] >= insert_idx)
				pos[j] = pos[j] + 1;
		}
	}

	// Step 8: Replace original list with sorted result
	list = large;
}

// void vecFordJohnson(std::vector<int>& list)
// {
// 	if (list.size() <= 1)
// 		return;
	
// 	std::vector<std::pair<int, int> > pairs;
// 	std::vector<int> large;
// 	std::vector<int> small;

// 	// Step 1: Make sorted pairs (a, b) where a < b
// 	for (std::size_t i = 0; i + 1 < list.size(); i += 2)
// 	{
// 		int a = list[i];
// 		int b = list[i + 1];
// 		if (a > b)
// 			std::swap(a, b);
// 		large.push_back(b);
// 		small.push_back(a);
// 		pairs.push_back(std::make_pair(a, b));
// 	}

// 	// Step 2: If list has an odd element, add it to small
// 	if (list.size() % 2 != 0)
// 		small.push_back(list[list.size() - 1]);
	
// 	// Step 3: Call the function recursivly
// 	vecFordJohnson(large);

// 	// Step 4: Link large values to their original indexes in `large`
// 	std::unordered_map<int, size_t> link_map;
// 	for (size_t i = 0; i < large.size(); ++i)
// 		link_map[large[i]] = i;

// 	// Step 5: Initialize position vector (pos[i] = current index of original large[i])
// 	std::vector<size_t> pos(large.size());
// 	for (size_t i = 0; i < large.size(); ++i)
// 		pos[i] = i;

// 	// Step 6: Jacobsthal insertion of small into large
// 	std::vector<bool> inserted(small.size(), false);
// 	std::vector<size_t> insert_order = jacobsthalSequence(small.size());

// 	std::vector<int>::iterator insert_pos;

// 	for (std::size_t i = 0; i < insert_order.size(); ++i)
// 	{
// 		size_t idx = insert_order[i];
// 		if (idx >= small.size())
// 			break;
// 		if (inserted[idx] == false)
// 		{
// 			insert_pos = std::upper_bound(large.begin(), large.end(), small[idx]);
// 			large.insert(insert_pos, small[idx]);
// 			inserted[idx] = true;
// 		}
// 	}

// 	// Step 6: Insert remaining small values
// 	for (std::size_t i = 0; i < small.size(); ++i)
// 	{
// 		if (inserted[i] == false)
// 		{
// 			insert_pos = std::upper_bound(large.begin(), large.end(), small[i]);
// 			large.insert(insert_pos, small[i]);
// 			inserted[i] = true;
// 		}
// 	}

// 	// Step 7: Replace original list with sorted result
// 	list = large;
// }


