/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:54:43 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/28 15:41:12 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <set>
# include <iterator>
# include <ctime>
# include <cstdlib>
# include <list>
# include "color.hpp"

#ifndef RANDMAX
# define RANDMAX 10000
#endif

class Span
{
	private:
		std::list<int>			_numbers;
		const unsigned int		_size;
	public:
		// Constructeur
		Span();
		Span(unsigned int nb);
		Span(const Span &other);
		// Overloading Operateur
		Span &operator=(const Span &other);
		// Destructor
		~Span();
		// Member Functions
		void					addNumber(unsigned int nb);
		void					addNumbers(unsigned int count, ...);
		std::list<int>			&getNumbers();
		unsigned int			shortestSpan(void);
		unsigned int 			longestSpan(void);
		class elementIsAlready : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Element already exist");
			}
		};
		class sizeSpanTooSmall : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Size of span is too small");
			}
		};
		class outOfBounds : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("out of bounds");
			}
		};
};

std::ostream		&operator<<(std::ostream &o, Span &src);

#endif