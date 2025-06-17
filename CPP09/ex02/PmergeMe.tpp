/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:02:45 by nezumickey        #+#    #+#             */
/*   Updated: 2025/06/17 12:52:37 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

template <typename Iterator>
void printContainer(Iterator begin, Iterator end)
{
	for (Iterator it = begin; it != end; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename Iterator, typename T>
Iterator binarySearch(Iterator begin, Iterator end, const T& value)
{
	Iterator left = begin;
	Iterator right = end;
	while (left < right)
	{
		Iterator mid = left + (right - left) / 2;

		/* Print the value being compared */
		// std::cout << "Comparing " << value << " with " << *mid << std::endl;
		if (*mid == value)
			return mid;

		else if (*mid < value)
			left = mid + 1;

		else
			right = mid;
	}
	return left;
}

template <typename ContainerType>
void merge(typename ContainerType::iterator iterBegin, typename ContainerType::iterator iterMid, typename ContainerType::iterator iterEnd)
{
	typedef typename ContainerType::value_type ValueType;

	std::vector<ValueType> leftSubArray(iterBegin, iterMid + 1);
	std::vector<ValueType> rightSubArray(iterMid + 1, iterEnd + 1);

	typename std::vector<ValueType>::iterator iterRight = rightSubArray.begin();

	while (iterRight != rightSubArray.end())
	{
		typename std::vector<ValueType>::iterator insertPosition = binarySearch(leftSubArray.begin(), leftSubArray.end(), *iterRight);
		leftSubArray.insert(insertPosition, *iterRight);

		/* Print the ASCII representation before moving elements */
		// std::cout << "Inserting " << *iterRight << std::endl;
		// std::cout << "container value before insertion: ";
		// printContainer(leftSubArray.begin(), leftSubArray.end());

		/* Print the ASCII representation after moving elements */
		// std::cout << "container value after insertion: ";
		// printContainer(leftSubArray.begin(), leftSubArray.end());

		++iterRight;
	}

	typename ContainerType::iterator iterMerge = iterBegin;
	for (typename std::vector<ValueType>::iterator iterLeft = leftSubArray.begin(); iterLeft != leftSubArray.end(); ++iterLeft)
	{
		*iterMerge = *iterLeft;
		++iterMerge;
	}
}

template <typename Container>
void insertionSort(typename Container::iterator begin, typename Container::iterator end)
{
	typename Container::iterator current;

	for (current = begin + 1; current <= end; ++current)
	{
		typename Container::value_type currentValue = *current;
		typename Container::iterator insertionPoint = binarySearch(begin, current, currentValue);

		/* Print the ASCII representation before moving elements */
		// std::cout << "Inserting " << currentValue << std::endl;
		// std::cout << "container value before insertion: ";
		// printContainer(begin, end + 1);

		/* Move elements and insert the current value */
		for (typename Container::iterator it = current; it > insertionPoint; --it)
		{
			*it = *(it - 1);
		}
		*insertionPoint = currentValue;

		/* Print the ASCII representation after moving elements */
		// std::cout << "container value after insertion: ";
		// printContainer(begin, end + 1);
	}
}

template <typename T>
void mergeInsertSortHelper(T& container, typename T::iterator left, typename T::iterator right)
{
	if (std::distance(left, right) <= 1)
		insertionSort<T>(left, right);

	else
	{
		typename T::iterator mid = left + std::distance(left, right) / 2;
		
		/* Print the ASCII representation before merging */
		// std::cout << "\nBefore merging: ";
		// printContainer(left, mid);
		// printContainer(mid + 1, right);
		
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