/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:58:24 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/23 01:47:12 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//_________________________________  Constructor  ______________________________

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "Default MutantStack constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other)
{
	std::cout << "Copy MutantStack constructor called" << std::endl;
	*this = other;
}

//_________________________________  Destructor  _______________________________

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &other)
{
	std::cout << "MutantStack copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this.~MutantStack();
		new (this) MutantStack(other);
	}
	return *this;
}

template<typename T>
std::ostream &operator<<(std::ostream &o, MutantStack<T> &ms)
{
	o << "MutantStack: " << ms.size() << " elements" << std::endl;
	for (typename MutantStack<T>::iterator it = ms.begin(); it != ms.end(); ++it)
		o << *it << " ";
	return o;
}

//______________________________  Member Functions  ____________________________

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template<typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

template<typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

template<typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template<typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}
