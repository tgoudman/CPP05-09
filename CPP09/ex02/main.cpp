/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:29:15 by raveriss          #+#    #+#             */
/*   Updated: 2025/06/19 09:26:04 by nezumickey       ###   ########.fr       */
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

std::string intToString(int number)
{
	std::ostringstream oss;
	oss << number;
	return oss.str();
}
template <typename T>
T		checkArgument(int argc, char **argv, T container)
{
	for (int i = 1; i < argc; ++i)
	{
		if (!isPositiveInteger(argv[i]) || argc == 1)
		{
			std::cerr << RESET << RED << "Error: Invalid input '" << argv[i] << "'. All inputs must be positive integers." << RESET << std::endl << std::endl;
			exit (1);
		}
		long long verifie = std::strtoll(argv[i], NULL, 10);
		if (verifie > INT_MAX)
		{
			std::cerr << RESET << RED << "Error: Input value '" << argv[i] << "' exceeds the maximum allowed integer value (INT_MAX)." << RESET << std::endl;
			exit (1);
		}
		int num = std::atoi(argv[i]);
		container.push_back(num);
	}
	return (container);
}
int main(int argc, char* argv[])
{
	if (argc == 1)
		return (std::cerr << RESET << RED << "Error: no Input value." << std::endl, 1);
	if (DEBUG)
		std::cout << "Debugging activate." << std::endl;
	std::vector<int> data = checkArgument(argc, argv, std::vector<int>());
	std::deque<int> deq = checkArgument(argc, argv, std::deque<int>());

	PmergeMe pmergeMe;
	pmergeMe.setData(data);
	pmergeMe.setDeq(deq);

	std::cout << CYAN << "Before" << RESET << " : ";
	for (std::vector<int>::iterator it = pmergeMe.getData().begin(); it != pmergeMe.getData().end(); ++it)
		std::cout << *it << " ";

	std::clock_t startVector = std::clock();
	sortsFordJohnson(pmergeMe.getData());
	std::clock_t endVector = std::clock();

	double durationVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000;
	std::cout << CYAN << "\nAfter" << RESET << " : ";
	for (std::vector<int>::iterator it = pmergeMe.getData().begin(); it != pmergeMe.getData().end(); ++it)
		std::cout << *it << " ";

	std::clock_t startDeque = std::clock();
	sortsFordJohnson(pmergeMe.getDeq());
	std::clock_t endDeque = std::clock();

	double durationDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000;
	std::cout << std::endl;

	const char* vectorColor = (durationVector <= durationDeque) ? GREEN : RED;
	const char* dequeColor = (durationDeque <= durationVector) ? GREEN : RED;
	std::cout << "Time to process a range of " << pmergeMe.getData().size() << " elements with std:: " << vectorColor << "vector "
				<< RESET << ": " << std::fixed << std::setprecision(5) << durationVector << " us" << std::endl;
	std::cout << "Time to process a range of " << pmergeMe.getData().size() << " elements with std:: " << dequeColor << "deque "
				<< RESET << ": " << durationDeque << " us" << std::endl;
}
