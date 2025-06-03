/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:28:29 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/21 14:42:58 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"
class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		size_t				_grade;
	public:
		// Constructeur
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		// Overloading Operateur
		Bureaucrat &operator=(const Bureaucrat &other);
		// Destructor
		~Bureaucrat();
		// Member Functions
		void		upGrade(void);
		void		downGrade(void);
		void		signForm(AForm &form);
		void		executeForm(AForm const & form);
		
		// Getters
		std::string	getName( void ) const;
		size_t		getGrade( void ) const;
		// Setters
		void		setGrade(int grade);
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a);

#endif