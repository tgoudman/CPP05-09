/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertFromInt.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:08:04 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/13 11:26:19 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convertFromInt(const std::string &input)
{
	char	c;
	long	i;
	float	f;
	double	d;

	i = atol(input.c_str());
	if (i >= MIN_CHAR && i <= MAX_CHAR)
	{
		c = static_cast<char>(i);
		if (isprint(c))
			std::cout << GOLD "char:   \t'" << c << "'" RESET << std::endl;
		else
			std::cout << RED "char:   \t" << "non displayable" RESET << std::endl;
	}
	else
		std::cout << RED "char:   \t" << "impossible" RESET << std::endl;
	if (i < MIN_INT || i > MAX_INT)
		std::cout << RED "int:    \t" << "impossible" RESET << std::endl;
	else
		std::cout << GREEN << "int:    \t" << i << RESET << std::endl;
	f = static_cast<float>(i);
	std::cout << CYAN << "float:  \t" << std::fixed << std::setprecision(1) << f  << "f" RESET << std::endl;
	d = static_cast<double>(i);
	std::cout << YELLOW << "double: \t" << d << RESET << std::endl;
}

bool ScalarConverter::isInteger(std::string const &literal)
{
	size_t i = 0;
	if (literal.empty())
		return false;
	if (literal[0] == '-' || literal[0] == '+')
	{
		if (literal.length() == 1)
			return false;
		i = 1;
	}
	while (i < literal.length())
	{
		if (!isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

