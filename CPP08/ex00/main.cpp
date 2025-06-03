/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:07:51 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/28 15:15:14 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	int search;
	{
		std::cout << "------------------" << std::endl;
		std::cout << YELLOW << "Test with vector" << RESET << std::endl;
		std::cout << "------------------" << std::endl;
		std::vector<int> tab;
		std::vector<int>::iterator it;
		std::srand(time(0));
		int search = rand() % 10;
		for (int i = 0; i < 10; i++)
		{
			tab.push_back(rand() % 10);
		}
		std::cout << "Searching for " << RED << search << RESET << std::endl;
		std::cout << "tab : ";
		try
		{
			std::cout << "HERE " << easyfind(tab, search) << std::endl;
			std::cout << "Element found" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "tab : ";
		for (it = tab.begin(); it != tab.end(); it++)
		{
			if (*it == search)
				std::cout << RED;
			else
				std::cout << RESET;
			std::cout << *it << " ";
		}
	}
std::cout << RESET << std::endl;
	{   
		std::cout << "------------------" << std::endl;
		std::cout << YELLOW << "Test with deque" << RESET << std::endl;
		std::cout << "------------------" << std::endl;
		std::deque<int> tab;
		std::deque<int>::iterator it;
		search = rand() % 10;
		for (int i = 0; i < 10; i++)
		{
			tab.push_back(rand() % 10);
		}
		std::cout << "Searching for " << RED << search << RESET << std::endl;
		std::cout << "tab : ";
		try
		{
			easyfind(tab, search);
			std::cout << "Element found" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		for (it = tab.begin(); it != tab.end(); it++)
		{
			if (*it == search)
				std::cout << RED;
			else
				std::cout << RESET;
			std::cout << *it << " ";
		}
	}
std::cout << RESET << std::endl;
	{
		std::cout << "------------------" << std::endl;
		std::cout << YELLOW << "Test with string" << RESET << std::endl;
		std::cout << "------------------" << std::endl;
		std::string tab;
		std::string::iterator it;
		search = rand() % 10;
		for (int i = 0; i < 10; i++)
		{
			tab.push_back((rand() % 10) + '0');
		}
		std::cout << "Searching for " << RED << search <<  RESET << std::endl;
		std::cout << "tab : ";
		try
		{
			easyfind(tab, search);
			std::cout << "Element found" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		for (it = tab.begin(); it != tab.end(); it++)
		{
			if (*it == search + '0')
				std::cout << RED;
			else
				std::cout << RESET;
			std::cout << *it << " ";
		}
	}
std::cout << RESET << std::endl;
	{
	std::cout << "------------------" << std::endl;
	std::cout << YELLOW << "Test with list" << RESET << std::endl;
	std::cout << "------------------" << std::endl;
	std::list<int> tab;
	std::list<int>::iterator it;
	search = rand() % 10;
	for (int i = 10; i > 0; i--)
		tab.push_back(rand() % 10);
	std::cout << "Searching for " << RED << search << RESET << std::endl;
	std::cout << "tab : ";
	try
	{
		easyfind(tab, search);
		std::cout << "Element found" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (it = tab.begin(); it != tab.end(); it++)
	{
		if (*it == search)
			std::cout << RED;
		else
			std::cout << RESET;
		std::cout << *it << " ";
	}
	}
std::cout << RESET << std::endl;
}