/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:57:19 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/23 17:45:54 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include "color.hpp"

int	main(void)
{
	int				intArray[] = {1, 2, 3, 4};
	double			dblArray[] = {4.4, 3.3, 2.2, 1.1};
	bool			bolArray[] = {true, false};
	char			chrArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::string	strArray[] = {"string1", "string2", "string3"};

	std::cout << BLUE "INT ARRAY" << std::endl;
	iter(intArray, 4, printer);
	std::cout << RESET << std::endl;

	std::cout << RED "DOUBLE ARRAY" << std::endl;
	iter(dblArray, 4, printer);
	std::cout << RESET << std::endl;

	std::cout << GOLD "BOOL ARRAY" << std::endl;
	iter(bolArray, 2, printer);
	std::cout << RESET << std::endl;

	std::cout << GREEN "CHAR ARRAY" << std::endl;
	iter(chrArray, 5, printer);
	std::cout << RESET << std::endl;

	std::cout << "STRING ARRAY" << std::endl;
	iter(strArray, 3, printer);
	std::cout << RESET << std::endl;

	return (0);
}