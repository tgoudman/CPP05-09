/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:54:42 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/23 01:43:57 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <iterator>
# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// Constructeur
		MutantStack();
		MutantStack(const MutantStack &other);
		// Overloading Operateur
		MutantStack &operator=(const MutantStack &other);
		// Destructor
		~MutantStack();
		// Member Functions
		iterator begin(void);
		iterator end(void);

		const_iterator begin(void) const;
		const_iterator end(void) const;
		
		reverse_iterator rbegin(void);
		reverse_iterator rend(void);

		const_reverse_iterator rbegin(void) const;
		const_reverse_iterator rend(void) const;

};

template<typename T>
std::ostream &operator<<(std::ostream &o, MutantStack<T> &ms);
# include "MutantStack.tpp"

#endif