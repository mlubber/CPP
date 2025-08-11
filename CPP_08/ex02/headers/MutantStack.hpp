#pragma once

#include <iostream>
#include <deque>
#include <stack>
#include <ctime>

template <class T, class Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:

		using	std::stack<T, Container>::c;

		MutantStack() = default;
		MutantStack(const MutantStack& other) = default;
		~MutantStack() = default;

		MutantStack&			operator=(const MutantStack& other) = default;
		const T&				operator[](size_t index);

		typedef typename Container::iterator iterator;
		iterator				begin();
		iterator				end();

		typedef typename Container::const_iterator const_iterator;
		const_iterator			cbegin() const;
		const_iterator			cend() const;

		typedef typename Container::reverse_iterator reverse_iterator;
		reverse_iterator		rbegin();
		reverse_iterator		rend();

		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		const_reverse_iterator	crbegin() const;
		const_reverse_iterator	crend() const;
};

#include "../sources/templates/MutantStack.tpp"