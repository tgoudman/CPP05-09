/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:20:43 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/23 10:34:56 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	ScalarConverter::isOther(const std::string &input)
{
	const std::string	specials[] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" };
	for (int i = 0; i < 6; i++)
	{
		if (input == specials[i])
			return (true);
	}
	return (false);
}

void	ScalarConverter::toOther(const std::string &input)
{
	std::cout << RED "char:   \t" << "impossible" RESET << std::endl;
	std::cout << RED "int:    \t" << "impossible" RESET << std::endl;

	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << CYAN "float:  \t" << input << RESET << std::endl;
		std::string inputFixed = input.substr(0, input.size() - 1);
		std::cout << YELLOW "double: \t" << inputFixed << RESET << std::endl;
	}
	else
	{
		std::cout << CYAN << "float:  \t" << input << "f" RESET << std::endl;
		std::cout << YELLOW "double: \t" << input << RESET << std::endl;
	}
}