/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:38:04 by nezumickey        #+#    #+#             */
/*   Updated: 2025/05/11 16:41:35 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{	
	public:
		// Constructeur
		Intern();
		Intern(const Intern &other);
		// Overloading Operateur
		Intern &operator=(const Intern &other);
		// Destructor
		~Intern();
		// Member Functions
		AForm	*makeForm(std::string nameForm, std::string targetForm);
};

#endif