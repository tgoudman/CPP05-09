/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:17:57 by nezumickey        #+#    #+#             */
/*   Updated: 2025/06/17 17:41:51 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/RPN.hpp"

//_________________________________  Constructor  ______________________________

RPN::RPN()
{
	std::cout << "Default RPN constructor called" << std::endl;
}

RPN::RPN(const RPN &other)
{
	std::cout << "Copy RPN constructor called" << std::endl;
	*this = other;
}

//_________________________________  Destructor  _______________________________

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

RPN	&RPN::operator=(const RPN &other)
{
	std::cout << "RPN copy assignment operator called" << std::endl;
	if (this != &other)
	this->stack = other.stack;
	return *this;
}

//______________________________  Member Functions  ____________________________

bool RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false); 
}

bool RPN::isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

void	RPN::argvToString(char **argv)
{
	std::stringstream ss;
	std::string expression;
	int i = 1;
	int j = 0;

	while (argv[i])
	{
		while (argv[i][j])
		{
			ss << argv[i][j];
			j++;
		}
		i++;
	}
	expression = ss.str();
	expEval(expression);
}

int RPN::rpnCalculator(int a, int b, char op)
{
	if (op == '+')
		return (b+a);
	else if (op == '-')
		return (b-a);
	else if (op == '/')
	{
		if (a == 0)
		{
			std::cout << "Error" << std::endl;
			this->~RPN();
			exit(EXIT_FAILURE);
		}
		return (b/a);
	}
	else
		return (b*a);
}

void RPN::expEval(std::string exp)
{
	size_t i = 0;
	int res;

	while (i < exp.length())
	{
		while (isspace(exp[i]))
			i++;
		if (isDigit(exp[i]))
		{
			char tmp[2] = {exp[i], '\0'};
			this->stack.push(atoi(tmp));
		}
		else if (isOperator(exp[i]))
		{
			if (this->stack.size() < 2)
			{
				std::cout << "Error" << std::endl;
				this->~RPN();
				exit(EXIT_FAILURE);
			}
			int a = this->stack.top();
			this->stack.pop();
			int b = this->stack.top();
			this->stack.pop();
			res = rpnCalculator(a, b, exp[i]);
			this->stack.push(res);
		}
		else
		{
			std::cout << "Error" << std::endl;
			this->~RPN();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (this->stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		this->~RPN();
		exit(EXIT_FAILURE);
	}
	std::cout << this->stack.top() << std::endl;
}
