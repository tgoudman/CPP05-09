/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:37:50 by nezumickey        #+#    #+#             */
/*   Updated: 2025/05/11 19:23:25 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "color.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//_________________________________  Constructor  ______________________________

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Copy Intern constructor called" << std::endl;
	*this = other;
}

//_________________________________  Destructor  _______________________________

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

Intern	&Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &other)
		return *this;
	return *this;
}

//______________________________  Member Functions  ____________________________

static AForm	*createPresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*createRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string formToCreate, const std::string targetForForm)
{
	AForm *(*allForms[])(const std::string target) = {&createPresident, &createRobot, &createShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formToCreate == forms[i])
		{
			std::cout << "Intern creates " << formToCreate << " now" << std::endl;
			return (allForms[i](targetForForm));
		}
	}
	std::cout << RED << "Intern cannot create a form called " << formToCreate << RESET << std::endl;
	return (NULL);
}

