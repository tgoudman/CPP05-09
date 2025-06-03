/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:22:20 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/15 23:46:45 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

//_________________________________  Constructor  ______________________________

template <typename T>
Array<T>::Array() : _elements(new T[0]), _size(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Custom constructor called" << std::endl;
	_elements = new T[n]();
	_size = n;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	size_t i = -1;
	_size = other._size;
	_elements = new T[_size];
	while(++i < _size)
			_elements[i] = other._elements[i];
}

//_________________________________  Destructor  _______________________________

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor called" << std::endl;
	delete [] _elements;
}

//__________________________________  Operator  ________________________________

template <typename T>
Array<T>&	Array<T>::operator=(const Array &other)
{
	size_t i = -1;
	std::cout << "Operator = called" << std::endl;
	if (*this != &other)
	{
		delete [] _elements;
		_size = other._size;
		_elements = new T[other._size];
		while(++i < other._size)
			_elements[i] = other._elements[i];
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw outOfBounds();
	return(_elements[index]);
}

template <typename T>
std::ostream	&operator<<(std::ostream &o, Array<T> const &i)
{
	size_t j = -1;
	while(++j < i.size())
		o << i[j] << std::endl;
	return (o);
}

//______________________________  Member Functions  ____________________________

template<typename T>
void	Array<T>::display(void)
{
	size_t i = -1;
	while(++i < _size)
		std::cout << _elements[i] << std::endl;
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}
//______________________________  Exception Handling  ___________________________

template<typename T>
const char *Array<T>::outOfBounds::what() const throw()
{
	static const std::string err = RED + std::string("Index out of bounds.") + RESET;
	return (err.c_str());
}