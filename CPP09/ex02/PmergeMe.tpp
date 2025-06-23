/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:02:45 by nezumickey        #+#    #+#             */
/*   Updated: 2025/06/19 09:24:09 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

template <typename Iterator, typename T>
Iterator binarySearch(Iterator begin, Iterator end, const T& value)
{
	while (begin < end)
	{
		Iterator mid = begin + (end - begin) / 2;
		if (*mid == value)
			return mid;
		else if (*mid < value)
			begin = mid + 1;
		else
			end = mid;
	}
	return begin;
}

template <typename ContainerType>
void merge(typename ContainerType::iterator it, typename ContainerType::iterator itMidle, typename ContainerType::iterator ite)
{
	typedef typename ContainerType::value_type ValueType;

	std::vector<ValueType> leftSubArray(it, itMidle + 1);
	std::vector<ValueType> rightSubArray(itMidle + 1, ite + 1);

	typename std::vector<ValueType>::iterator iterRight = rightSubArray.begin();
	while (iterRight != rightSubArray.end())
	{
		typename std::vector<ValueType>::iterator insertPosition = binarySearch(leftSubArray.begin(), leftSubArray.end(), *iterRight);
		leftSubArray.insert(insertPosition, *iterRight);
		++iterRight;
	}

	typename ContainerType::iterator iterMerge = it;
	for (typename std::vector<ValueType>::iterator iterLeft = leftSubArray.begin(); iterLeft != leftSubArray.end(); ++iterLeft)
	{
		*iterMerge = *iterLeft;
		++iterMerge;
	}
}

template <typename Container>
void switchElement(typename Container::iterator begin, typename Container::iterator end)
{
	if (*begin < *end)
		return;
	typename Container::iterator swap = begin;
	*begin = *end;
	*end = *swap;
}

template <typename T>
void mergeInsertSortHelper(T& container, typename T::iterator left, typename T::iterator right)
{
	if (std::distance(left, right) <= 1)
		switchElement<T>(left, right);
	else
	{
		typename T::iterator mid = left + std::distance(left, right) / 2;
		mergeInsertSortHelper(container, left, mid);
		mergeInsertSortHelper(container, mid + 1, right);
		merge<T>(left, mid, right);
	}
}

template <typename T>
void sortsFordJohnson(T& container)
{
	mergeInsertSortHelper(container, container.begin(), container.end() - 1);
}