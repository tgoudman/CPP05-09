/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:53:42 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/31 10:24:44 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		BitcoinExchange exchange(argv[1]);
		exchange.insertMap();
		exchange.parseFile();
	}
	else
		std::cerr << RED "Error: could not open file." RESET << std::endl;
	return 0;
}


