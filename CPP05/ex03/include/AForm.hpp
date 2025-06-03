/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:17:12 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/09 16:20:06 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include <string>

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign;
		const int			_execSign;
	public:
		// Constructeur
		AForm();
		AForm(std::string name, int sign = 50, int execSign = 50);
		AForm(const AForm &other);
		// Overloading Operateur
		AForm &operator=(const AForm &other);
		// Destructor
		virtual ~AForm();
		// Getters
		std::string				getName(void) const;
		bool					getSigned(void) const;
		int						getSign(void) const;
		int						getExecSign(void) const;
		// Member Functions
		void			beSigned(Bureaucrat &person);
		virtual void	execute(Bureaucrat const & executor) const = 0;

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
		class			isNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	
};
std::ostream	&operator<<(std::ostream &o, AForm &input);

#endif