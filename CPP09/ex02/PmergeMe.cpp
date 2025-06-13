/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:02:45 by nezumickey        #+#    #+#             */
/*   Updated: 2025/06/13 13:38:13 by tgoudman         ###   ########.fr       */
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
	typename T::iterator	it;
	typename T::iterator	itLast;
	typename T::iterator	ite;
	long					jump;
	size_t					pairNbr;

	jump = pairLevel * 2;
	it = container.begin();
	ite = container.end();
	pairNbr = container.size() / pairLevel;
	if(pairNbr < 2)
		return;
	if (pairLevel == 3)
		return;
	std::cout << "pairLevel :" << pairLevel << std::endl;
	while (std::distance(it, ite) >= jump)
	{
		typename T::iterator nextPair = next(it, jump -1);
		if (compare(nextPair, it))
		{
			std::cout << RED << "swaping pair: " << *it << " " << *nextPair << RESET << std::endl;
			_swap_pair(it, pairLevel);
		}
		std::advance(it, jump);
	}
	
	_insertion_sort(container, pairLevel * 2);


std::cout << CYAN << "Before: " << RESET;
	for(typename T::iterator test = container.begin(); test != container.end(); test++)
		std::cout << *test << " ";
std::cout << std::endl;
	T leftArray;
	T rightArray;
	T finalTab;
	it = container.begin();
	unsigned long i = 0;
	while (it != ite)
	{
		if (i > container.size() / pairLevel)
			break;
		typename T::iterator nextElem = next(it, pairLevel - 1);
		if (i >= (container.size() / pairLevel) / 2)
			rightArray.push_back(*nextElem);
		else
			leftArray.push_back(*nextElem);
		it++;
		i++;
	}

	it = leftArray.begin();
	ite = leftArray.end();
	bool inserted = false;
	i = 2;
	while (leftArray.size() != 0)
	{
		typename T::iterator nextElem = next(leftArray.begin(), (leftArray.size() / i));
		std::cout << leftArray.size() << std::endl; 
		if (leftArray.size() == 1 || leftArray.size() == 2)
		{
			nextElem = leftArray.begin();
		}
		if (finalTab.size() == 0)
		{
			finalTab.push_back(*nextElem);
			leftArray.erase(nextElem);
			continue;
		}
		for (typename T::iterator itFinal = finalTab.begin(); itFinal != finalTab.end(); itFinal++)
		{
			inserted = false;
			if (*nextElem < *itFinal)
			{
				finalTab.insert(itFinal, *nextElem);
				leftArray.erase(nextElem);
				inserted = true;
				break;
			}
		}
		if(!inserted)
		{
			finalTab.push_back(*nextElem);
			leftArray.erase(nextElem);			
		}
		it++;
		i++;
	}


	it = rightArray.begin();
	ite = rightArray.end();
	inserted = false;
	i = 2;
	while (rightArray.size() != 0)
	{
		typename T::iterator nextElem = next(rightArray.begin(), (rightArray.size() / i));
		std::cout << rightArray.size() << std::endl; 
		if (rightArray.size() == 1 || rightArray.size() == 2)
		{
			nextElem = rightArray.begin();
		}
		if (finalTab.size() == 0)
		{
			finalTab.push_back(*nextElem);
			rightArray.erase(nextElem);
			continue;
		}
		for (typename T::iterator itFinal = finalTab.begin(); itFinal != finalTab.end(); itFinal++)
		{
			inserted = false;
			if (*nextElem < *itFinal)
			{
				finalTab.insert(itFinal, *nextElem);
				rightArray.erase(nextElem);
				inserted = true;
				break;
			}
		}
		if(!inserted)
		{
			finalTab.push_back(*nextElem);
			rightArray.erase(nextElem);			
		}
		it++;
		i++;
	}
std::cout << BLUE << "leftTab: " << RESET;
	for (typename T::iterator l = leftArray.begin(); l != leftArray.end(); ++l)
		std::cout << *l << " ";
std::cout << RED << "rightTab: " << RESET;
	for (typename T::iterator l = rightArray.begin(); l != rightArray.end(); ++l)
		std::cout << *l << " ";
std::cout << YELLOW << "finalTab: " << RESET;
	for (typename T::iterator l = finalTab.begin(); l != finalTab.end(); ++l)
		std::cout << *l << " ";
std::cout << std::endl;

}

