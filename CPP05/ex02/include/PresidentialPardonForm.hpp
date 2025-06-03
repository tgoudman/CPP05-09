/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:51:37 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/20 18:39:11 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	public:
		// Constructeur
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		// Overloading Operateur
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		// Destructor
		~PresidentialPardonForm();
		// Member Functions
		virtual void	execute(Bureaucrat const &executor) const;
		std::string getTarget(void) const;
};

#endif