/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:18 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/21 16:53:21 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"
#include "color.hpp"

//_________________________________  Constructor  ______________________________

Bureaucrat::Bureaucrat() :  _name(BLUE + std::string("Major Bob") + RESET), _grade(5)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
	std::cout << _name << " whith grade: " << _grade <<std::endl;
}

Bureaucrat::Bureaucrat(unsigned int grade) : _name(BLUE + std::string("Major Bob") + RESET)
{
	try{setGrade(grade);}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() <<std::endl;
		_grade = 50;
		return;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() <<std::endl;
		_grade = 50;
		return;
	}
	_grade = grade;
	std::cout << "Custom Bureaucrat constructor called" << std::endl;
	std::cout << _name << " whith grade: " << _grade <<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
	*this = other;
}

//_________________________________  Destructor  _______________________________

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->~Bureaucrat();
		new (this)Bureaucrat(other);
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a)
{
	o << "Bureaucrat " << a.getName() << ":\tgrade: " << a.getGrade();
	return (o);
}

//______________________________  Member Functions  ____________________________

void	Bureaucrat::upGrade(void)
{
	try
		{(setGrade(_grade - 1));}
	catch(Bureaucrat::GradeTooHighException const &o)
	{
		std::cerr << o.what() << std::endl;
	}
}

void	Bureaucrat::downGrade(void)
{
	try
		{(setGrade(_grade + 1));}
	catch(Bureaucrat::GradeTooLowException const &o)
	{
		std::cerr << o.what() << std::endl;
	}
}

//__________________________________  Getters  _________________________________

std::string	Bureaucrat::getName( void ) const
{
	return (_name);
}

size_t		Bureaucrat::getGrade( void ) const
{
	return (_grade);
}

//__________________________________  Setters  _________________________________

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		this->_grade = grade;
		std::cout << _name << " whith new grade: " << _grade <<std::endl;
	}
}

//_________________________________  SubClass  _________________________________

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	static const std::string err = RED + std::string("Grade to low.") + RESET;
	return (err.c_str());
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	static const std::string err = RED + std::string("Grade to High.") + RESET;
	return (err.c_str());
}