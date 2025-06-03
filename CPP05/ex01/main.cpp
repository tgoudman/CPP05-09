/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:25 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/21 10:20:50 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/Form.hpp"
#include "color.hpp"

int main()
{
	Bureaucrat	bob("Major Bob", 52);
	Form		*licenseCar;

	try{
		licenseCar = new Form("License Car");
		std::cout << bob.getName() << " with grade: " << bob.getGrade() << std::endl;
		std::cout << licenseCar->getName() << YELLOW 
		<< " grade necessary to signed: " << RESET << licenseCar->getGrade() << std::endl;
		// licenseCar->beSigned(bob);
		bob.signForm(*licenseCar);
		bob.upGrade();
		bob.upGrade();
		std::cout << *licenseCar << std::endl;
		licenseCar->beSigned(bob);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
		delete licenseCar;
		return (1);
	}
	delete licenseCar;
	return (0);
}
