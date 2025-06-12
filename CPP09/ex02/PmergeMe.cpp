/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:02:45 by nezumickey        #+#    #+#             */
/*   Updated: 2025/06/12 22:01:08 by nezumickey       ###   ########.fr       */
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
	_insertionSort<std::vector<int> >(vec, 1); 
}

void PmergeMe::sort_deque(std::deque<int>& deque)
{
	// _insertionSort<std::deque<int> >(deque, 1);
	(void)deque;
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
void	PmergeMe::_insertionSort(T& container, int pairLevel)
{
	typename T::iterator it;
	typename T::iterator ite;
	size_t pairNbr;
	int jump;

	jump = pairLevel * 2;
	it = container.begin();
	ite = container.end();
	pairNbr = container.size() / pairLevel;
	if(pairNbr < 2)
		return;
	while (std::distance(it, ite) > jump)
	{
		typename T::iterator nextPair = next(it, jump -1);
		if (compare(nextPair, it))
			_swap_pair(it, pairLevel);
		// std::cout << "distance: " << std::distance(it, nextPair) << "\n" << "it begin: " << *it << "\n" << "it last: " << *nextPair << "\n" <<std::endl;
		// if (*it + jump >= static_cast<int>(container.size()))
		// 	break;
		std::advance(it, jump);
	}

	_insertionSort(container, pairLevel * 2);
	

	size_t i;
	i = 0;
	T leftTable;
	T rightTable;
	it = container.begin();
	ite = container.end();
	while(std::distance(it, ite) > jump)
	{
		if (i >= container.size() / 2 / jump)
		{
			rightTable.push_back(*it);
		}
		else
		{
			leftTable.push_back(*it);
		}
		std::advance(it, jump);
		i++;
	}
	std::cout << std::endl;
	T finalTab;
	it = container.begin();
	std::cout << "finalTable: \n";
	while(std::distance(it, ite) > jump)
	{

		typename T::iterator nextPair = next(it, jump -1);
		std::cout << RED << *it << RESET << " ";
		if (compare(nextPair, it))
			_swap_pair(it, pairLevel);
		leftTable.push_back(*it);
		std::advance(it, jump);
		i++;
	}
	std::cout << std::endl;
	for(typename T::iterator test = container.begin(); test != container.end(); test++)
		std::cout << *test << " ";
	std::cout << std::endl;
	// std::cout << "Losers: ";
	// for (typename T::iterator l = losers.begin(); l != losers.end(); ++l)
	// 	std::cout << *l << " ";
	// std::cout << std::endl;
	// // 1. Extraire les "left" (plus petits éléments des paires)
	// T leftTab;
	// typename T::iterator itLeft = container.begin();

	// while (std::distance(itLeft, container.end()) >= pairLevel * 2) {
	// 	typename T::iterator leftElement = next(itLeft, pairLevel - 1);
	// 	leftTab.push_back(*leftElement);
	// 	std::advance(itLeft, pairLevel * 2);
	// }


}

