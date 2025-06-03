/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:17:12 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/20 19:04:30 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include <string>
# include "color.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign;
		const int			_execSign;
	public:
		// Constructeur
		Form();
		Form(std::string name, unsigned int sign = 50, unsigned int execSign = 50);
		Form(const Form &other);
		// Overloading Operateur
		Form &operator=(const Form &other);
		// Destructor
		~Form();
		// Member Functions
		std::string		getName(void);
		int				getGrade(void);
		bool			getSigned(void);
		void			beSigned(const Bureaucrat &person);
		// Setters
		bool			checkSign(unsigned int sign);
		bool			checkExecSign(unsigned int sign);
		class			GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class			GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class			isSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	
};
std::ostream	&operator<<(std::ostream &o, Form &input);

#endif