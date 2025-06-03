/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:17:35 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/09 16:16:15 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/AForm.hpp"

//_________________________________  Constructor  ______________________________

AForm::AForm() : _name("Default"), _signed(false), _sign(0), _execSign(0)
{
	std::cout << "Default Form constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign, int execSign) :
_name(name), _signed(false),
_sign(sign), _execSign(execSign)
{
	if (sign > 150)
		throw(GradeTooLowException());
	else if (sign < 0)
		throw(GradeTooHighException());
	if (execSign > 150)
		throw(GradeTooLowException());
	else if (execSign < 0)
		throw(GradeTooHighException());
	std::cout << "Custom Form constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : 
_name(other._name),_signed(false)
, _sign(other._sign), _execSign(other._execSign)
{
	std::cout << "Copy Form constructor called" << std::endl;
}

//_________________________________  Destructor  _______________________________

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

AForm	&AForm::operator=(const AForm &other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, AForm &input)
{
	if (input.getSigned())
		o << "Form name: " << input.getName() << " is signed";
	else
		o << "Form name: " << input.getName() << " is not signed";
	return (o);
}

//______________________________  Member Functions  ____________________________

std::string		AForm::getName(void) const
{
	return (_name);
}

int		AForm::getSign(void) const
{
	return (_sign);
}

int		AForm::getExecSign(void) const
{
	return (_execSign);
}

bool		AForm::getSigned(void) const
{
	return (_signed);
}

void		AForm::setSigned(void)
{
	_signed = true;
}

void			AForm::beSigned(Bureaucrat &person)
{
	if (person.getGrade() > (size_t)_sign && !_signed)
	{
		std::cout << person.getName() << " couldn’t sign " << this->getName() << " because ";
		throw(GradeTooLowException());
	}
	else if (_signed == false)
	{
		this->setSigned();
		std::cout << person.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << person.getName() << " couldn’t sign " << this->getName() << " because ";
		std::cout << getName() << " Form is already signed" << std::endl;
	}
}

//_________________________________  SubClass  _________________________________

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}
const char	*AForm::isSignedException::what() const throw()
{
	return("Form is already signed");
}
const char	*AForm::isNotSignedException::what() const throw()
{
	return("Form is not signed");
}