/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:21:40 by tgoudman          #+#    #+#             */
/*   Updated: 2025/06/02 16:40:37 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/BitcoinExchange.hpp"

//_________________________________  Constructor  ______________________________

BitcoinExchange::BitcoinExchange(const std::string &filename) : _filename(filename)
{
	std::cout << "BitcoinExchange Constructor called" << std::endl;
}
 BitcoinExchange:: BitcoinExchange(const  BitcoinExchange &other)
{
	std::cout << "Copy  BitcoinExchange constructor called" << std::endl;
	*this = other;
}

//_________________________________  Destructor  _______________________________

 BitcoinExchange::~ BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

 BitcoinExchange	& BitcoinExchange::operator=(const  BitcoinExchange &other)
{
	std::cout << " BitcoinExchange copy assignment operator called" << std::endl;
	if (this != &other)
	{
	}
	return *this;
}
std::ostream &operator<<(std::ostream &o, const BitcoinExchange &i)
{
	std::map<std::string, float>::const_iterator it = i.getArray().begin();
	std::map<std::string, float>::const_iterator ite = i.getArray().end();

	while (it != ite)
	{
		o << it->first << " => " << it->second << std::endl;
		++it;
	}
	return o;
}
//______________________________  Member Functions  ____________________________

std::string removeChar(const std::string &str, char c)
{
	std::string result;
	if (c != '0')
	{
		for (size_t i = 0; i < str.length(); ++i) {
			if (str[i] != c)
				result += str[i];
			else
				return result;
		}
		return result;
	}
	else
	{
		unsigned int i = 0;
		while (str[i] == ' ')
			++i;
		result = &str[i];
	}
	return result;
}

bool	isDigits(const std::string &str, int size)
{
	if (str[size] != '-')
		return false;
	while (--size)
	{
		if (str[size] < '0' || str[size] > '9')
			return false;
	}
	return true;
}

int	checkLineYear(std::string dateLine)
{
	if (dateLine.size() != 5)
		throw(BitcoinExchange::InvalidFormatException());	
	if (!isDigits(dateLine, 4))
		throw(BitcoinExchange::InvalidFormatException());
	if (atoi(dateLine.c_str()) > 2025)
		throw(BitcoinExchange::outOfBoundsException());
	return dateLine.size();
}

int checkLineMonth(std::string dateLine)
{
	if (dateLine.size() != 3)
		throw(BitcoinExchange::InvalidFormatException());	
	if (!isDigits(dateLine, 2))
		throw(BitcoinExchange::IsNotDigitException());
	if (atoi(dateLine.c_str()) > 12 || atoi(dateLine.c_str()) < 1)
		throw(BitcoinExchange::outOfBoundsException());
	return (dateLine.size());
}

int checkLineDay(std::string dateLine)
{
	dateLine[2] = '-';
	if (dateLine.size() != 3)
		throw(BitcoinExchange::InvalidFormatException());	
	if (!isDigits(dateLine, 2))
	{
		throw(BitcoinExchange::IsNotDigitException());
	}
	if (atoi(dateLine.c_str()) > 31 || atoi(dateLine.c_str()) < 1)
		throw(BitcoinExchange::outOfBoundsException());
	return (dateLine.size());
}

int		checkLineType(std::string dateLine)
{
	if (dateLine.compare(" | ") == 0)
		return (3);
	else
		throw(BitcoinExchange::InvalidTypeException());
}

float		checkLineValue(std::string dateLine)
{
	float value;
	int i = 0;
	bool point = false;
	while(dateLine[i] == ' ')
		++i;
	if(dateLine[i] == '\0')
		throw(BitcoinExchange::InvalidValueException());
	if(dateLine[i] == '-')
		throw(BitcoinExchange::ValueNotPositiveException());
	while(dateLine[i] != ' ' && dateLine[i] != '\0')
	{
		if (dateLine[i] == '.' && point)
			throw(BitcoinExchange::InvalidValueException());
		if (dateLine[i] == '.')
		{
			point = true;
			++i;
		}
		if (dateLine[i] == '\0')
			break;
		else if ((dateLine[i] < '0' || dateLine[i] > '9') && dateLine[i] != '.' && dateLine[i] != '0')
			throw(BitcoinExchange::InvalidValueException());
		++i;
	}
	dateLine[i] = '\0';
	std::istringstream iss(dateLine);
	iss >> value;
	if (value > 1000)
		throw(BitcoinExchange::ValueTooLargeException());
	return (value);
}

void	BitcoinExchange::insertMap()
{
	float value;
	std::string line;
	std::ifstream csv("data.csv");
	getline(csv, line);
	while(getline(csv, line))
	{
		std::istringstream iss(line.substr(11));
		iss >> value;
		_array[line.substr(0, 10)] = value;
	}
}

float BitcoinExchange::exchangeCalculator(std::string const &date, float value)
{
	std::string yearStrCsv;
	std::string monthStrCsv;
	std::string dayStrCsv;
	std::string yearStrInput = date.substr(0, 4);
	std::string monthStrInput = date.substr(5, 2);
	std::string dayStrInput = date.substr(8, 2);
	std::map<std::string, float>::iterator it = _array.begin();
	std::map<std::string, float>::iterator itBefore = _array.begin();
	std::map<std::string, float>::iterator ite = _array.end();
	std::map<std::string, float>::iterator itf = _array.find(date);
	if (itf != _array.end())
		return itf->second * value;
	else 
	{
		while (it != ite)
		{
			yearStrCsv = it->first.substr(0, 4);
			monthStrCsv = it->first.substr(5, 2);
			dayStrCsv = it->first.substr(8, 2);
			if(yearStrCsv >= yearStrInput && monthStrCsv >= monthStrInput &&  dayStrCsv >= dayStrInput)
				return itBefore->second * value;
			itBefore = it;
			it++;
		}
		it--;
		return it->second * value;
	}
	return it->second * value;
}

void	BitcoinExchange::parseFile()
{
	float value;
	std::string dateLine;
	std::string exchangeRate;

	std::ifstream	file(_filename.c_str());
	if (!file)
		throw (BitcoinExchange::InvalidInputException());
	std::string line;
	std::getline(file, line);
	while (getline(file, line))
	{
		dateLine = removeChar(line, '0');
		dateLine = removeChar(dateLine, '\n');
		if (!dateLine.empty())
		{
			try 
			{
				checkLineYear(dateLine.substr(0, 5));
				checkLineMonth(dateLine.substr(5, 3));
				checkLineDay(dateLine.substr(8, 3));
				checkLineType(dateLine.substr(10, 3));
				value = checkLineValue(dateLine.substr(13));
				float result = this->exchangeCalculator(dateLine.substr(0, 10), value);
				std::cout << dateLine.substr(0, 10) << " => " << value
				<< " = " << result << std::endl;
			}
			catch (std::exception &e)
			{
				std::cerr << "Error: " << e.what();
				if (e.what() == outOfBoundsException().what())
					std::cerr << " " << dateLine.substr(0, 10);
				std::cerr << std::endl;
			}
		}	
	}
}

const char *BitcoinExchange::InvalidInputException::what() const throw()
{
	return(RED "file cannot open." RESET);
}

const char *BitcoinExchange::IsNotDigitException::what() const throw()
{
	return(RED "not a digit." RESET);
}
const char *BitcoinExchange::outOfBoundsException::what() const throw()
{
	return(RED "bad input." RESET);
}
const char *BitcoinExchange::InvalidFormatException::what() const throw()
{
	return(RED "Invalid Format YYYY-MM-JJ." RESET);
}

const char *BitcoinExchange::InvalidTypeException::what() const throw()
{
	return(RED "Invalid Type date | value." RESET);
}

const char *BitcoinExchange::InvalidValueException::what() const throw()
{
	return(RED "Invalid value." RESET);
}

const char *BitcoinExchange::ValueTooLargeException::what() const throw()
{
	return(RED "too large a number." RESET);
}

const char *BitcoinExchange::ValueNotPositiveException::what() const throw()
{
	return(RED "not a positive number." RESET);
}