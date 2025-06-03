/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:25 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/21 16:31:14 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "color.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	Bureaucrat bureaucrat("Bob", 2);
	AForm *president = NULL;
	AForm *shrub = NULL;
	AForm *robot = NULL;
	std::srand(time(NULL));
	Intern newbie;

	try{
		robot = newbie.makeForm("RobotomyRequestForm", "Bob");
		robot->beSigned(bureaucrat);
		robot->execute(bureaucrat);
		std::cout << GREEN << "RobotomyRequestForm executed successfully!" << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try{
		shrub = newbie.makeForm("ShrubberyCreationForm", "Bob");
		shrub->beSigned(bureaucrat);
		shrub->execute(bureaucrat);
		std::cout << GREEN << "ShrubberyCreationForm executed successfully!" << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		delete robot;
		robot = NULL;
		std::cout << e.what() << std::endl;
	}
	try
	{
		president = newbie.makeForm("PresidentialPardonForm", "Bob");
		president->beSigned(bureaucrat);
		president->execute(bureaucrat);
	}
	catch (const std::exception &e)
	{
		delete shrub;
		delete robot;
		robot = NULL;
		shrub = NULL;
		std::cout << "Exception: " << e.what() << std::endl;
	}
	if (president)
		delete president;
	if (robot)
		delete robot;
	if (shrub)
		delete shrub;
}
