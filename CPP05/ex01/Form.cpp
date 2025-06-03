/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:17:35 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/21 18:21:35 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Form.hpp"

//_________________________________  Constructor  ______________________________

Form::Form() : _name("Default"), _signed(false), _sign(0), _execSign(0)
{
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int sign, unsigned int execSign) :
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

Form::Form(const Form &other) : 
_name(other._name),_signed(false)
, _sign(other._sign), _execSign(other._execSign)
{
	std::cout << "Copy Form constructor called" << std::endl;
}

//_________________________________  Destructor  _______________________________

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

Form	&Form::operator=(const Form &other)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->~Form();
		new (this)Form(other);
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Form &input)
{
	if (input.getSigned())
		o << "Form name: " << input.getName() << " is signed";
	else
		o << "Form name: " << input.getName() << " is not signed";
	return (o);
}

//______________________________  Member Functions  ____________________________

std::string		Form::getName(void)
{
	return (_name);
}
int		Form::getGrade(void)
{
	return (_sign);
}

bool		Form::getSigned(void)
{
	return (_signed);
}

bool	Form::checkSign(unsigned int sign)
{
	if (sign > 150)
		throw(GradeTooLowException());
	else if (sign < 0)
		throw(GradeTooHighException());
	else
		return (true);
}

bool	Form::checkExecSign(unsigned int sign)
{
	if (sign > 150)
		throw(GradeTooLowException());
	else if (sign < 0)
		throw(GradeTooHighException());
	else
		return (true);
}
void			Form::beSigned(const Bureaucrat &person)
{
	if (person.getGrade() > (size_t)_sign && !_signed)
	{
		std::cout << person.getName() << " couldn’t sign " << this->getName() << " because ";
		throw(GradeTooLowException());
	}
	else if (_signed == false)
	{
		_signed = true;
		std::cout << person.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << person.getName() << " couldn’t sign " << this->getName() << " because ";
		std::cout << getName() << " Form is already signed" << std::endl;
	}
}

//_________________________________  SubClass  _________________________________

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low");
}
const char	*Form::isSignedException::what() const throw()
{
	return("Form is already signed");
}
