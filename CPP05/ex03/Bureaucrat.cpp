/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:18 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/21 16:54:07 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "color.hpp"
#include "AForm.hpp"

//_________________________________  Constructor  ______________________________

Bureaucrat::Bureaucrat() :  _name(BLUE + std::string("Major Bob") + RESET), _grade(5)
{
	std::cout << "Default Bureaucrat constructor called" << std::endl;
	// std::cout << _name << " whith grade: " << _grade <<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :  _name(name), _grade(grade)
{
	std::cout << "Custom Bureaucrat constructor called" << std::endl;
	// std::cout << _name << " whith grade: " << _grade <<std::endl;
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

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << ":\n\tgrade: " << a->getGrade() << std::endl;
	return (o);
}

//______________________________  Member Functions  ____________________________

void		Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned())
		std::cout << "Form is already sign" << std::endl;
	else
	{
		if (_grade <= (size_t)form.getExecSign())
			form.beSigned(*this);
		else
		{
			std::cout << this->getName() << " couldn’t sign " << form.getName() << " because ";
			throw(GradeTooLowException());
		}
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try 
	{
		form.execute(*this);
	}
	catch(std::exception &e)
	{
		std::cout << this->getName() << " couldn’t execute " << form.getName() << " because"
		<< RED <<  " grade too low" << RESET << std::endl;
	}
}

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
	static const std::string err = RED + std::string("Grade too low.") + RESET;
	return (err.c_str());
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	static const std::string err = RED + std::string("Grade too High.") + RESET;
	return (err.c_str());
}