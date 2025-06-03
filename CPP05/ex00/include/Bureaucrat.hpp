/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:28:29 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/16 09:59:06 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		size_t				_grade;
	public:
		// Constructeur
		Bureaucrat();
		Bureaucrat(unsigned int grade);
		Bureaucrat(const Bureaucrat &other);
		// Overloading Operateur
		Bureaucrat &operator=(const Bureaucrat &other);
		// Destructor
		~Bureaucrat();
		// Member Functions
		void		upGrade(void);
		void		downGrade(void);
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

std::ostream	&operator<<(std::ostream &o, Bureaucrat &a);


#endif