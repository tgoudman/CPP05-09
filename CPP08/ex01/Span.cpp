/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:54:46 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/28 16:03:32 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <cstdarg>

//_________________________________  Constructor  ______________________________

Span::Span() : _size(std::numeric_limits<unsigned int>::max())
{
	std::cout << "Default Span constructor called" << std::endl;
}

Span::Span(unsigned int nb) : _size(nb)
{
	std::cout << "Custom Span constructor called" << std::endl;
}

Span::Span(const Span &other) : _size(other._size)
{
	std::cout << "Copy Span constructor called" << std::endl;
	*this = other;
}

//_________________________________  Destructor  _______________________________

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

Span	&Span::operator=(const Span &other)
{
	std::cout << "Span copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->~Span();
		new (this)Span(other);
	}
	return *this;
}

std::ostream		&operator<<(std::ostream &o, Span &src)
{
	std::list<int> tab = src.getNumbers();
	std::list<int>::iterator it;

	for (it = tab.begin(); it != tab.end(); ++it)
		o << ".." << *it << std::endl;
	return (o);
}
//______________________________  Member Functions  ____________________________

std::list<int>	&Span::getNumbers()
{
	return (_numbers);
}

void	Span::addNumber(unsigned int nb)
{
	if (_numbers.size() >= _size)
		throw(outOfBounds());
	_numbers.push_back(nb);
	_numbers.sort();
}

void	Span::addNumbers(unsigned int count, ...)
{
	va_list args;
	unsigned int nb;
	va_start(args, count);

	for(unsigned int i = 0; i < count; i++)
	{
		nb = va_arg(args, unsigned int);
		addNumber(nb);
		_numbers.sort();
	}
	va_end(args);
}

unsigned int 			Span::shortestSpan(void)
{
	std::list<int>::iterator it;
	it = _numbers.begin();
	unsigned int range;
	unsigned int minRange;
	unsigned int prev;

	prev = *it;
	minRange = std::numeric_limits<unsigned int>::max();
	if(_numbers.size() < 2)
		throw(sizeSpanTooSmall());
	while(++it != _numbers.end())
	{
		range = *it - prev;
		if(minRange > range)
			minRange = range;
		prev = *it;
	}
	return(minRange);
}

unsigned int 			Span::longestSpan(void)
{
	if(_numbers.size() < 2)
		throw(sizeSpanTooSmall());
	unsigned int first = *(_numbers.begin());
	unsigned int last = *(--_numbers.end());
	return (last - first);
}
