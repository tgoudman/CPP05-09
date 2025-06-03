/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:56:15 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/21 17:15:21 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//_________________________________  Constructor  ______________________________

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
 AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Custom ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "Copy ShrubberyCreationForm constructor called" << std::endl;
	*this = other;
}

//_________________________________  Destructor  _______________________________

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->~ShrubberyCreationForm();
		new (this)ShrubberyCreationForm(other);
	}
	return *this;
}

//______________________________  Member Functions  ____________________________

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getExecSign())
		throw (Bureaucrat::GradeTooLowException());
	else if (!getSigned())
		throw (AForm::isNotSignedException());
	else
	{
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		std::ofstream file((_target + "_shrubbery").c_str());
		if (file.is_open()) {
			file << "       ^\n";
			file << "      ^^^\n";
			file << "     ^^^^^\n";
			file << "    ^^^^^^^\n";
			file << "   ^^^^^^^^^\n";
			file << "      |||\n";
			file << "      |||\n";
			file.close();
		} else {
			std::cerr << "Could not open file for writing\n";
		}
	}
}
