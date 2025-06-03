/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:30:52 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/20 18:39:39 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERRYCREATIONFORM_HPP
# define SHRUBBERRYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "color.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string		_target;
	public:
		// Constructeur
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		// Overloading Operateur
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		// Destructor
		~ShrubberyCreationForm();
		// Member Functions
		virtual void	execute(Bureaucrat const &executor) const;
	
};

#endif