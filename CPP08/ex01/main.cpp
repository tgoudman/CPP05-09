/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:52:17 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/28 16:33:14 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main()
{
	Span tab;
	unsigned int nb;
	std::srand(time(0));

	for (int i = 0; i < 10; ++i)
	{
		nb = std::rand() % 10000;
		try {tab.addNumber(nb);}
		catch (std::exception &e)
		{
			std::cout << e.what() << ": " << RED <<  nb << RESET << std::endl;
		}
	}

	// std::cout << tab << std::endl;
	std::cout << tab.shortestSpan() <<std::endl;
	std::cout << tab.longestSpan() <<std::endl;

	Span sp = Span(6);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
		sp.addNumber(11);
	}
	catch(std::exception &e)
	{
		std::cerr << "Can't insert number because it is " << e.what() << std::endl;
	}
	std::cout << sp << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	Span tabtwo = Span();
	try
	{
		tabtwo.addNumbers(9, 25, 45, 99, 40, 54, 130, 86, 64, 54);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << tabtwo << std::endl;
	std::cout << tabtwo.shortestSpan() << std::endl;
	std::cout << tabtwo.longestSpan() << std::endl;
	return 0;
}
