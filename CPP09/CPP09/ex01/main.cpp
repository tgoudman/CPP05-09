/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:17:51 by nezumickey        #+#    #+#             */
/*   Updated: 2025/05/31 17:45:05 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "Please enter a RPN expression" << std::endl;
	else if (argc > 2)
		std::cout << "too many arguments" << std::endl;
	else
	{
		RPN rpn;
		rpn.argvToString(argv);
	}
	return 0;
}

