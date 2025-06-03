/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertFromFloat.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:11:25 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/13 11:12:18 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convertFromFloat(const std::string &input)
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
	if (i < MIN_INT || i > MAX_INT)
		std::cout << RED "int:   \t" << "impossible" RESET << std::endl;
	else
		std::cout << GREEN << "int:    \t" << i << RESET << std::endl;
	std::cout << CYAN << "float:  \t" << std::fixed << std::setprecision(1) << f  << "f" RESET << std::endl;
	std::cout << YELLOW << "double: \t" << d << RESET << std::endl;
}

bool ScalarConverter::isFloat(std::string const &literal)
{
	size_t i;
	bool hasDot;

	i = 0;
	hasDot = false;
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
		else if (literal[i] == 'f' && i == literal.length() - 1)
			return true;
		else if (!isdigit(literal[i]))
			return false;
		i++;
	}
	return false;
}

