/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:34:11 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/11 13:11:58 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	public:
		// Constructeur
		RobotomyRequestForm();
		RobotomyRequestForm(std::string	target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		// Overloading Operateur
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		// Destructor
		~RobotomyRequestForm();
		// Member Functions
		virtual void	execute(Bureaucrat const & executor) const;
		std::string		getTarget(void) const;

	
};

#endif