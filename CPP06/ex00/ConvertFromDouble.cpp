/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertFromDouble.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:13:11 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/13 11:14:54 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::isDouble(std::string const &literal)
{
	size_t i = 0;
	bool hasDot;
	bool hasDigit;
	
	hasDot = false;
	hasDigit = false;
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
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (std::isdigit(literal[i]))
			hasDigit = true;
		else
			return false;
		i++;
	}
	if (hasDot && hasDigit)
		return true;
	return false;
}

void	ScalarConverter::convertFromDouble(std::string const &input)
{
	char	c;
	int		i;
	float	f = static_cast<float>(atof(input.c_str()));
	double	d = atof(input.c_str());

	if (f >= MIN_CHAR && f <= MAX_CHAR)
	{
		c = static_cast<char>(f);
		if (isprint(c))
			std::cout << GOLD "char:   \t'" << c << "'" RESET << std::endl;
		else
			std::cout << RED "char:   \t" << "non displayable" RESET << std::endl;
	}
	else
		std::cout << RED "char:   \t" << "impossible" RESET << std::endl;
	i = static_cast<int>(f);
	if (static_cast<long>(f) < MIN_INT || static_cast<long>(f) > MAX_INT)
		std::cout << RED "int:     \t" << "impossible" RESET << std::endl;
	else
		std::cout << GREEN << "int:    \t" << i << RESET << std::endl;
	if (f < MIN_FLOAT || f > MAX_FLOAT)
		std::cout << RED "float:     \t" << "impossible" RESET << std::endl;
	else 
		std::cout << CYAN << "float:  \t" << std::fixed << std::setprecision(1) << f  << "f" RESET << std::endl;
	std::cout << YELLOW << "double: \t" << d << RESET << std::endl;
}
