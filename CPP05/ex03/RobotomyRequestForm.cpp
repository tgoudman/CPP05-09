/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:07:36 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/21 17:17:37 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

//_________________________________  Constructor  ______________________________

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Custom RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	std::cout << "Copy RobotomyRequestForm constructor called" << std::endl;
	*this = other;
}


//_________________________________  Destructor  _______________________________

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->~RobotomyRequestForm();
		new (this)RobotomyRequestForm(other);
	}
	return *this;
}

//______________________________  Member Functions  ____________________________

std::string		RobotomyRequestForm::getTarget(void) const
{
	return(_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if ((int)executor.getGrade() > this->getExecSign())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::isNotSignedException());
	else if (rand() % 2)
	{
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		std::cout << "BRRRRRRRRRRRRRR 🛠️⚡️\n" << this->getTarget() << " was robotomized" << std::endl;
	}
	else
	{
		std::cout << executor.getName() << " executed " << getName() << std::endl;
		std::cout << "Robotomy failed" << std::endl;
	}
}