/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:07:24 by nezumickey        #+#    #+#             */
/*   Updated: 2025/05/23 10:37:48 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//_________________________________  Constructor  ______________________________

ScalarConverter::ScalarConverter()
{
	std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "Copy ScalarConverter constructor called" << std::endl;
	*this = other;
}

//_________________________________  Destructor  _______________________________

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	if (this != &other)
		return *this;
	return *this;
}

//______________________________  Member Functions  ____________________________


bool ScalarConverter::isPseudoFloat(std::string const &literal){
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return true;
	return false;
}

bool ScalarConverter::isPseudoDouble(std::string const &literal){
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	return false;
}

void	ScalarConverter::convert(std::string const &literal)
{
	bool (*typeConvert[])(const std::string &literal) = {&isInteger, &isChar, &isFloat, &isDouble, &isOther};
	void (*convertTo[])(const std::string &literal) = {&convertFromInt, &convertFromChar, &convertFromFloat, &convertFromDouble, &toOther};
	 
	std::string literals[] = {"int", "char", "float", "double", "pseudo-literals"};
	std::cout << "ScalarConverter convert function called with literal: " << literal << std::endl;
	for (int i = 0; i < 5; i++)
	{
		if (typeConvert[i](literal))
		{
			std::cout << "The literal is of type: " << literals[i] << std::endl;
			convertTo[i](literal);
			return;
		}
	}
	throw(ScalarConverter::invalidArgument());
}

//__________________________________  Exeption  ________________________________

const char	*ScalarConverter::invalidArgument::what() const throw()
{
	static const std::string err = RED + std::string("Invalid input for integer conversion.") + RESET;
	return(err.c_str());
}
