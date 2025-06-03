/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:15:30 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/15 23:35:15 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>
# include "color.hpp"

template<typename T>
class Array
{
	private:
		T 			*_elements;
		unsigned int _size;
	public:
		// Constructeur
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		// // Overloading Operateur
		Array	&operator=(const Array &other);
		T		&operator[](unsigned int index) const;
		// Destructor
		~Array();

		// Member Functions
		void 			display(void);
		unsigned int	size(void) const;

		class outOfBounds : public std::exception
		{
			public:
				const char *what() const throw();
		};
};


template<typename T>
std::ostream &operator<<(std::ostream &o, const Array<T> &array);

# include "Array.tpp"


#endif