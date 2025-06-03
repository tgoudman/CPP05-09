/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:16:46 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/21 17:17:54 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//_________________________________  Constructor  ______________________________

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Custom PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	std::cout << "Copy PresidentialPardonForm constructor called" << std::endl;
	*this = other;
}

//_________________________________  Destructor  _______________________________

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->~PresidentialPardonForm();
		new (this)PresidentialPardonForm(other);
	}
	return *this;
}

//______________________________  Member Functions  ____________________________

std::string PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
	if ((int)executor.getGrade() > this->getExecSign())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::isNotSignedException());
	else
	{
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}
