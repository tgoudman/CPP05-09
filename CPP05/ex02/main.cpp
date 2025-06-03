/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:25 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/21 15:18:54 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "include/AForm.hpp"
#include "color.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(time(NULL));
	ShrubberyCreationForm *shrubberyForm1 = new ShrubberyCreationForm("ShrubberyBob");
	RobotomyRequestForm *robotomyForm1 = new RobotomyRequestForm("RobotomyBob");
	PresidentialPardonForm *presidentialForm1 = new PresidentialPardonForm("PresidentialBob");
	std::string	name = BLUE + std::string("Bob") + RESET;
	Bureaucrat bob(name, 140);
	name = GREEN + std::string("Zarbi") + RESET;
	Bureaucrat zarbi(name, 60);
	name = CYAN + std::string("Wish") + RESET;
	Bureaucrat wish(name, 50);


	std::cout << "_______________________________\n" << std::endl;
	std::cout << YELLOW  << "Trying to execute shrubberyForm" << RESET << std::endl;
	std::cout << "_______________________________" << std::endl;
	try
	{
		// shrubberyForm1->beSigned(bob);
		bob.signForm(*shrubberyForm1);
		bob.executeForm(*shrubberyForm1);
	}
	catch(std::exception &e)
	{
		std::cerr << "couldn’t execute " << robotomyForm1->getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	std::cout << "_______________________________\n" << std::endl;
	std::cout << YELLOW << "Trying to execute robotomyForm" << RESET << std::endl;
	std::cout << "_______________________________" << std::endl;
	try
	{
		robotomyForm1->beSigned(bob);
		robotomyForm1->execute(bob);
	}
	catch(std::exception &e)
	{
		std::cerr << "couldn’t execute " << robotomyForm1->getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	std::cout << "_______________________________\n" << std::endl;
	std::cout  << YELLOW << "Trying to execute presidentialForm" << RESET << std::endl;
	std::cout << "_______________________________" << std::endl;
	try
	{
		presidentialForm1->beSigned(bob);
		presidentialForm1->execute(bob);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "_______________________________\n" << std::endl;
	delete(shrubberyForm1);
	delete(robotomyForm1);
	delete(presidentialForm1);
	std::cout << "-------------------------------------------------------------------------------------------------------\n" << std::endl;
	ShrubberyCreationForm *shrubberyForm2 = new ShrubberyCreationForm("ShrubberyZarbi");
	RobotomyRequestForm *robotomyForm2 = new RobotomyRequestForm("RobotomyZarbi");
	PresidentialPardonForm *presidentialForm2 = new PresidentialPardonForm("PresidentialZarbi");
	std::cout << "_______________________________\n" << std::endl;
	std::cout << YELLOW  << "Trying to execute shrubberyForm" << RESET << std::endl;
	std::cout << "_______________________________" << std::endl;
	try
	{
		shrubberyForm2->beSigned(zarbi);
		shrubberyForm2->execute(zarbi);
	}
	catch(std::exception &e)
	{
		std::cerr << "couldn’t execute " << robotomyForm2->getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	std::cout << "_______________________________\n" << std::endl;
	std::cout << YELLOW << "Trying to execute robotomyForm" << RESET << std::endl;
	std::cout << "_______________________________" << std::endl;
	try
	{
		robotomyForm2->beSigned(zarbi);
		robotomyForm2->execute(zarbi);
	}
	catch(std::exception &e)
	{
		std::cerr << "couldn’t execute " << robotomyForm2->getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	std::cout << "_______________________________\n" << std::endl;
	std::cout  << YELLOW << "Trying to execute presidentialForm" << RESET << std::endl;
	std::cout << "_______________________________" << std::endl;
	try
	{
		presidentialForm2->beSigned(zarbi);
		presidentialForm2->execute(zarbi);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "_______________________________\n" << std::endl;
	delete(shrubberyForm2);
	delete(robotomyForm2);
	delete(presidentialForm2);
	std::cout << "-------------------------------------------------------------------------------------------------------\n" << std::endl;
	ShrubberyCreationForm *shrubberyForm3 = new ShrubberyCreationForm("ShrubberyWish");
	RobotomyRequestForm *robotomyForm3 = new RobotomyRequestForm("RobotomyWish");
	PresidentialPardonForm *presidentialForm3 = new PresidentialPardonForm("PresidentialWish");
	std::cout << "_______________________________\n" << std::endl;
	std::cout << YELLOW  << "Trying to execute shrubberyForm" << RESET << std::endl;
	std::cout << "_______________________________" << std::endl;
	try
	{
		shrubberyForm3->beSigned(wish);
		shrubberyForm3->execute(wish);
	}
	catch(std::exception &e)
	{
		std::cerr << "couldn’t execute " << robotomyForm3->getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	std::cout << "_______________________________\n" << std::endl;
	std::cout << YELLOW << "Trying to execute robotomyForm" << RESET << std::endl;
	std::cout << "_______________________________" << std::endl;
	try
	{
		robotomyForm3->beSigned(wish);
		robotomyForm3->execute(wish);
	}
	catch(std::exception &e)
	{
		std::cerr << "couldn’t execute " << robotomyForm3->getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
	std::cout << "_______________________________\n" << std::endl;
	std::cout  << YELLOW << "Trying to execute presidentialForm" << RESET << std::endl;
	std::cout << "_______________________________" << std::endl;
	try
	{
		presidentialForm3->beSigned(wish);
		presidentialForm3->execute(wish);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "_______________________________\n" << std::endl;
	delete(shrubberyForm3);
	delete(robotomyForm3);
	delete(presidentialForm3);
}
