/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertFromChar.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:09:50 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/13 11:19:28 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::isChar(std::string const &literal)
{
	if (literal.length() == 1 && literal[0] >= 32 && literal[0] <= 126)
	{
		return true;
	}
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		if (literal[1] >= 32 && literal[1] <= 126)
			return true;
	}
	return false;
}

void	ScalarConverter::convertFromChar(const std::string &input)
{
	char	c = input[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	if (input.size() == 3)
		if (input[0] == '\'' && input[2] == '\'')
			c = input[1];

	if (isprint(c))
		std::cout << GOLD << "char:   \t'" << c << "'" RESET << std::endl;
	else
		std::cout << RED "char:   \t" << "non displayable" RESET << std::endl;
	std::cout << GREEN << "int:    \t" << i << RESET << std::endl;
	std::cout << CYAN << "float:  \t" << std::fixed << std::setprecision(1) << f  << "f" RESET << std::endl;
	std::cout << YELLOW << "double: \t" << d << RESET << std::endl;
}