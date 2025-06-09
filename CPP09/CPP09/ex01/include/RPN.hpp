/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:17:47 by nezumickey        #+#    #+#             */
/*   Updated: 2025/05/31 17:42:20 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
# include <stack>
# include <sstream>

class RPN
{
	private:
		std::stack<int> stack;
	public:
		// Constructeur
		RPN();
		RPN(const RPN &other);
		// Overloading Operateur
		RPN &operator=(const RPN &other);
		// Destructor
		~RPN();
		// Member Functions
		void	expEval(std::string exp);
		bool	isOperator(char c);
		bool	isDigit(char c);
		int 	rpnCalculator(int a, int b, char op);
		void	argvToString(char **argv);
	
};

#endif