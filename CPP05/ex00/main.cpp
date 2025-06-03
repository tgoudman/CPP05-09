/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:29:25 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/20 15:13:39 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"

int main()
{
	Bureaucrat bob(-2);
	bob.upGrade();
	bob.upGrade();
	bob.upGrade();
	bob.upGrade();
	bob.upGrade();
	bob.upGrade();
	bob.upGrade();
	bob.setGrade(145);
	bob.downGrade();
	bob.downGrade();
	bob.downGrade();
	bob.downGrade();
	bob.downGrade();
	bob.downGrade();
	bob.downGrade();
	std::cout << bob.getName() << " whith grade: " << bob.getGrade() <<std::endl;
	std::cout << bob << std::endl;
	return 0;
}
