/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:19:37 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/23 12:09:29 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "color.hpp"

Base*	generate(void)
{
	int	choice = rand() % 3;

	switch (choice)
	{
		case (0): return new A();
		case (1): return new B();
		default: return new C();
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL) 
		std::cout << "Base is type A." << std::endl;
	else if (dynamic_cast<B*>(p) != NULL) 
		std::cout << "Base is type B." << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Base is type C." << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Base is type A." << std::endl;
	}
	catch (const std::exception& e) {/*std::cout << e.what() << std::endl;*/}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Base is type B." << std::endl;
	}
	catch (const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Base is type C." << std::endl;
	}
	catch (const std::exception& e) {}
}

int	main(void)
{
	std::cout << CLRALL;
	srand(time(0));
	Base* instances[NB_INSTANCES];
	
	for (int i = 0; i < NB_INSTANCES; ++i)
		instances[i] = generate();

	std::cout << GREY "Identify pointer:" RESET<< std::endl;
	for (int i = 0; i < NB_INSTANCES; ++i)
		identify(instances[i]);
	std::cout << std::endl;

	std::cout << GREY "Identifiy reference:" RESET << std::endl;
	for (int i = 0; i < NB_INSTANCES; ++i)
		identify(*instances[i]);

	for (int i = 0; i < NB_INSTANCES; ++i)
		delete instances[i];

	return (0);
}