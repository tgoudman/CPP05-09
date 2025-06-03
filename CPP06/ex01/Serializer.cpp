/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:48:09 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/14 10:05:49 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//_________________________________  Constructor  ______________________________

Serializer::Serializer()
{
	std::cout << "Default Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
	std::cout << "Copy Serializer constructor called" << std::endl;
	*this = other;
}

//_________________________________  Destructor  _______________________________

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

Serializer	&Serializer::operator=(const Serializer &other)
{
	std::cout << "Serializer copy assignment operator called" << std::endl;
	if (this != &other)
		return *this;
	return *this;
}

//______________________________  Member Functions  ____________________________

uintptr_t Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}