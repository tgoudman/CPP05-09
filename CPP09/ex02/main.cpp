/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:29:15 by raveriss          #+#    #+#             */
/*   Updated: 2025/06/16 21:07:16 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PmergeMe.hpp"

bool isPositiveInteger(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return !str.empty();
}

std::string formatWithSpaces(int number, int maxWidth)
{
	std::ostringstream oss;
	oss << number;
	std::string str = oss.str();
	int numSpaces = maxWidth - str.length();
	for (int i = 0; i < numSpaces; ++i)
	{
		str = " " + str;
	}
	return str;
}

std::string intToString(int number)
{
	std::ostringstream oss;
	oss << number;
	return oss.str();
}

int main(int argc, char* argv[])
{

	std::vector<int> data;
	std::deque<int> deq;

	for (int i = 1; i < argc; ++i)
	{
		if (!isPositiveInteger(argv[i]))
		{
			std::cerr << RESET << RED << "Error: Invalid input '" << argv[i] << "'. All inputs must be positive integers." << RESET << std::endl << std::endl;
			return 1;
		}
		long long verifie = std::strtoll(argv[i], NULL, 10);
		if (verifie > INT_MAX)
		{
			std::cerr << RESET << RED << "Error: Input value '" << argv[i] << "' exceeds the maximum allowed integer value (INT_MAX)." << RESET << std::endl;
			return 1;
		}
		int num = std::atoi(argv[i]);
		data.push_back(num);
		deq.push_back(num);
	}

	PmergeMe pmergeMe;
	pmergeMe.setData(data);
	pmergeMe.setDeq(deq);

	std::cout << CYAN << "/*                                  VECTOR                                   */\n" << RESET;

	std::cout << CYAN << "Before" << RESET << " : ";
	for (std::vector<int>::iterator it = pmergeMe.getData().begin(); it != pmergeMe.getData().end(); ++it)
	{
		std::cout << *it << " ";
	}

	if (pmergeMe.getData().size() > 26)
		std::cout << std::endl;

	std::clock_t startVector = std::clock();
	sortsFordJohnson(pmergeMe.getData());
	std::clock_t endVector = std::clock();
	double durationVector = 1000000.0 * (endVector - startVector) / CLOCKS_PER_SEC;

	std::cout << CYAN << "\nAfter" << RESET << " : ";
	for (std::vector<int>::iterator it = pmergeMe.getData().begin(); it != pmergeMe.getData().end(); ++it)
	{
		std::cout << *it << " ";
	}

	if (pmergeMe.getData().size() > 26 || pmergeMe.getDeq().size() <= 10)
		std::cout << std::endl;


	std::cout << CYAN << "/*                                   DEQUE                                   */\n" << RESET;

	std::cout << CYAN << "Before" << RESET << " : ";
	for (std::deque<int>::iterator it = pmergeMe.getDeq().begin(); it != pmergeMe.getDeq().end(); ++it)
	{
		std::cout << *it << " ";
	}

	if (pmergeMe.getDeq().size() > 26 || pmergeMe.getDeq().size() > 10)
		std::cout << std::endl;

	std::clock_t startDeque = std::clock();
	sortsFordJohnson(pmergeMe.getDeq());
	std::clock_t endDeque = std::clock();
	double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

	if (pmergeMe.getDeq().size() > 26 || pmergeMe.getDeq().size() <= 10)
		std::cout << std::endl;

	std::cout << CYAN << "After" << RESET << " : ";
	for (std::deque<int>::iterator it = pmergeMe.getDeq().begin(); it != pmergeMe.getDeq().end(); ++it)
	{
		std::cout << *it << " ";
	}

	if (pmergeMe.getDeq().size() > 26 || pmergeMe.getDeq().size() <= 10)
		std::cout << std::endl;

	std::cout << CYAN << "/*                                  RESULTAT                                 */\n" << RESET;

	const char* vectorColor = (durationVector <= durationDeque) ? GREEN : RED;
	const char* dequeColor = (durationDeque <= durationVector) ? GREEN : RED;

	int maxWidth = std::max(intToString(durationVector).length(), intToString(durationDeque).length());

	std::cout << CYAN << "Time to process a range of " << pmergeMe.getData().size() << " elements with std::\n" << RESET << vectorColor << " vector "
				<< RESET << ": " << formatWithSpaces(durationVector, maxWidth) << " us" << std::endl;
	std::cout << dequeColor << "  deque " << RESET << ": " << formatWithSpaces(durationDeque, maxWidth) << " us" << RESET << std::endl << std::endl;
}
