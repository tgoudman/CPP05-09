/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:47:27 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/13 15:27:02 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
	private:

		// Constructeur
		Serializer();
		Serializer(const Serializer &other);
		// Overloading Operateur
		Serializer &operator=(const Serializer &other);
		// Destructor
		~Serializer();
	public:
	
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	
};

#endif