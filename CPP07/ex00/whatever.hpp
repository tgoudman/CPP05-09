/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:10:18 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/15 10:52:59 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template<typename Tmin>
Tmin min(const Tmin& a, const Tmin& b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

template<typename Tswap>
void swap(Tswap& a, Tswap& b)
{
	Tswap tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template<typename Tmax>
Tmax max(const Tmax& a, const Tmax& b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

#endif