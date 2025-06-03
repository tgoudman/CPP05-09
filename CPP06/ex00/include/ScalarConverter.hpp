/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 20:06:51 by nezumickey        #+#    #+#             */
/*   Updated: 2025/05/23 10:26:10 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include "color.hpp"
# include <cctype>
# include <iomanip>
# include <limits>
# include <sstream>
# include <cstdlib>
# include <stdlib.h>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_CHAR std::numeric_limits<char>::min() //0
# define MAX_CHAR std::numeric_limits<char>::max() //12
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

class ScalarConverter
{
	private:
		// Constructeur
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		// Overloading Operateur
		ScalarConverter &operator=(const ScalarConverter &other);
		// Destructor
		~ScalarConverter();
		// Member Functions
		static bool isInteger(std::string const &literal);
		static bool isDouble(std::string const &literal);
		static bool isChar(std::string const &literal);
		static bool isFloat(std::string const &literal);
		static bool isPseudoFloat(std::string const &literal);
		static bool isPseudoDouble(std::string const &literal);
		static void	convertFromChar(const std::string &input);
		static void	convertFromFloat(const std::string &input);
		static void	convertFromInt(const std::string &input);
		static void convertFromDouble(std::string const &input);
		static void	toOther(const std::string &input);
		static bool	isOther(const std::string &input);

	public:
		static void convert(std::string const &literal);
	
	class invalidArgument : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif