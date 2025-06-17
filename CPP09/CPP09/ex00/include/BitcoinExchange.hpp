/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:54:00 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/31 11:28:31 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "color.hpp"
# include <iostream>
# include <map>
# include <exception>
# include <fstream>
# include <algorithm>
# include <cstdio>
# include <sstream>
# include <iomanip>

class  BitcoinExchange
{
	private:
		std::map<std::string, float> _array;
		std::string _filename;
		BitcoinExchange();
	public:
		// Constructeur
		BitcoinExchange(const std::string &filename);
		 BitcoinExchange(const  BitcoinExchange &other);
		// Overloading Operateur
		 BitcoinExchange &operator=(const  BitcoinExchange &other);
		// Destructor
		~ BitcoinExchange();
		// Member Functions
		std::string 						getFilename() const { return _filename; }
		const std::map<std::string, float> &getArray() const { return this->_array; }
		float								exchangeCalculator(std::string const &date, float value);
		void 								parseFile();
		void								insertMap();

	class InvalidInputException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class IsNotDigitException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	class outOfBoundsException: public std::exception
	{
		public:
			const char *what() const throw();
	};
	class InvalidFormatException: public std::exception
	{
		public:
			const char *what() const throw();
	};
	class InvalidTypeException: public std::exception
	{
		public:
			const char *what() const throw();
	};
	class InvalidValueException: public std::exception
	{
		public:
			const char *what() const throw();
	};
	class ValueTooLargeException: public std::exception
	{
		public:
			const char *what() const throw();
	};
	class ValueNotPositiveException: public std::exception
	{
		public:
			const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &o, const BitcoinExchange &i);


#endif