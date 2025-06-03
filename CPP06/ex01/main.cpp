/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:19:37 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/14 11:14:11 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Serializer.hpp"
#include "color.hpp"
#include <iostream>
#include <iomanip>

int main() 
{
    std::cout << std::left;
    std::cout << std::setw(25) << "Type" << "Taille (octets)\n";
    std::cout << "--------------------------------------\n";
    std::cout << std::setw(25) << "bool" << sizeof(bool) << "\n";
    std::cout << std::setw(25) << "char" << sizeof(char) << "\n";
    std::cout << std::setw(25) << "short" << sizeof(short) << "\n";
    std::cout << std::setw(25) << "int" << sizeof(int) << "\n";
    std::cout << std::setw(25) << "long" << sizeof(long) << "\n";
    std::cout << std::setw(25) << "long long" << sizeof(long long) << "\n";
    std::cout << std::setw(25) << "unsigned int" << sizeof(unsigned int) << "\n";
    std::cout << std::setw(25) << "unsigned long" << sizeof(unsigned long) << "\n";
    std::cout << std::setw(25) << "unsigned long long" << sizeof(unsigned long long) << "\n";
    std::cout << std::setw(25) << "float" << sizeof(float) << "\n";
    std::cout << std::setw(25) << "double" << sizeof(double) << "\n";
    std::cout << std::setw(25) << "long double" << sizeof(long double) << "\n";
    std::cout << std::setw(25) << "void*" << sizeof(void*) << "\n\n";

	Data a;
	Data *restored;

    a.str = "test";
    a.value = 54;
	a.secondString = "largeString";
	uintptr_t aNew = Serializer::serialize(&a);
	restored = Serializer::deserialize(aNew);
    std::cout << "\nStructure Data:\n\n";
    std::cout << std::setw(25) << "Data" << &a << "\n";
    std::cout << std::setw(25) << "Taille" << sizeof(a) << " octets\n";
    std::cout << RED << "Before " << RESET << std::setw(18) << "Contenu value" << a.value << "\n";
    std::cout << RED << "Before " << RESET << std::setw(18) << "Contenu str" << a.str << "\n";
    std::cout << RED << "Before " << RESET << std::setw(18) << "Contenu secondStr" << a.secondString << "\n";
    std::cout << std::setw(25) << "&restored " << restored << "\n";
    std::cout << std::setw(25) << "contenue de aNew " << "0x"<< std::hex << aNew << std::dec << "\n";
    std::cout << std::setw(25) << "Taille restored" << sizeof(restored) << " octets\n";
    std::cout << std::setw(25) << "Taille aNew" << sizeof(aNew) << " octets\n";
    std::cout << BLUE << "After " << RESET << std::setw(19) <<"Contenu value" << restored->value << "\n";
	std::cout << BLUE << "After " << RESET << std::setw(19) <<"Contenu str" << restored->str << "\n";
    std::cout << BLUE << "After " << RESET << std::setw(19) <<"Contenu secondStr" << restored->secondString << "\n";

    return 0;
}

