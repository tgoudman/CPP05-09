/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:02:45 by nezumickey        #+#    #+#             */
/*   Updated: 2025/06/10 01:27:27 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <set>

int PmergeMe::nbr_compare = 0;

//_________________________________  Constructor  ______________________________

PmergeMe::PmergeMe()
{
	std::cout << "Default PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
	std::cout << "Copy PmergeMe constructor called" << std::endl;
}

//_________________________________  Destructor  _______________________________

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	std::cout << "PmergeMe copy assignment operator called" << std::endl;
	if (this != &other)
	{
	}
	return *this;
}

//______________________________  Member Functions  ____________________________

long PmergeMe::jacobsthalNumber(long n) 
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3); 
}

void PmergeMe::sort_vec(std::vector<int>& vec) 
{
	_insertion_sort<std::vector<int> >(vec, 1); 
}

void PmergeMe::sort_deque(std::deque<int>& deque)
{
	_insertion_sort<std::deque<int> >(deque, 1);
}

int PmergeMe::F(int n)
{
	int result = 0;
	for (int k = 1; k <= n; ++k)
	{
		double value = (3.0 / 4.0) * k;
		std::cout << "-----------" << std::endl;
		std::cout << "value: " << value << std::endl; 
		result = static_cast<int>(ceil(log2(value)));
		std::cout << "result: " << result << std::endl;
		// std::cout << "-----------" << std::endl;
	}
	return (result);
}

template <typename T> 
bool compare(T it, T itNext)
{
	PmergeMe::nbr_compare++;
	return (*it < *itNext);
};

template <typename T> T next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template <typename T>
void 	PmergeMe::_swap_pair(T it, int pair_level)
{
	T start = next(it, -pair_level + 1);
	T end = next(it, pair_level);
	while (start != end)
	{
		std::iter_swap(start, next(start, pair_level));
		start++;
	}
}

template <typename T>
void	PmergeMe::_insertion_sort(T& container, int pairLevel)
{
	typename T::iterator it;
	typename T::iterator itLast;
	typename T::iterator ite;
	size_t pairNbr;
	int jump;
	long unsigned int bound;

	bound = 1;
	jump = pairLevel * 2;
	it = container.begin();
	ite = container.end();
	pairNbr = container.size() / pairLevel;
	if(pairNbr < 2)
		return;
	
	while (std::distance(it, ite) >= jump)
	{
		if (bound * 2 > container.size())
			break;
		typename T::iterator thisPair = next(it, pairLevel -1);
		typename T::iterator nextPair = next(it, jump -1);
		if (compare(nextPair, thisPair))
		{
			std::cout << RED << "swaping pair: " << *thisPair << " " << *nextPair << RESET << std::endl;
			_swap_pair(thisPair, pairLevel);
		}
		std::advance(it, jump);
		bound *= 2;
	}
	for(typename T::iterator test = container.begin(); test != container.end(); test++)
		std::cout << *test << " ";
	std::cout << std::endl;
	_insertion_sort(container, pairLevel * 2);
	T losers;
	it = container.begin();
	while (std::distance(it, ite) >= pairLevel)
	{
		typename T::iterator loser = next(it, pairLevel - 1);
		losers.push_back(*loser);
		std::advance(it, jump);
	}

	std::cout << "Losers: ";
	for (typename T::iterator l = losers.begin(); l != losers.end(); ++l)
		std::cout << *l << " ";
	std::cout << std::endl;
	// 1. Extraire les "left" (plus petits éléments des paires)
	T leftTab;
	typename T::iterator itLeft = container.begin();

	while (std::distance(itLeft, container.end()) >= pairLevel * 2) {
		typename T::iterator leftElement = next(itLeft, pairLevel - 1);
		leftTab.push_back(*leftElement);
		std::advance(itLeft, pairLevel * 2);
	}

	// 2. Générer les indices de Jacobsthal
	std::vector<size_t> jacobIndices;
	for (size_t j = 1; ; ++j) {
		long idx = jacobsthalNumber(j);
		if (static_cast<size_t>(idx) >= leftTab.size())
			break;
		jacobIndices.push_back(static_cast<size_t>(idx));
	}

	// 3. Compléter les indices manquants
	std::set<size_t> remainingIndices;
	for (size_t i = 0; i < leftTab.size(); ++i)
		remainingIndices.insert(i);
	for (size_t idx : jacobIndices)
		remainingIndices.erase(idx);

	std::vector<size_t> insertionOrder = jacobIndices;
	insertionOrder.insert(insertionOrder.end(), remainingIndices.begin(), remainingIndices.end());

	// 4. Insertion binaire dans le container
	for (size_t idx : insertionOrder) {
		typename T::value_type value = leftTab[idx];
		typename T::iterator insertPos = std::upper_bound(container.begin(), container.end(), value);
		container.insert(insertPos, value);
}

}

