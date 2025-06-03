/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:57:33 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/23 17:45:00 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename Tprint>
void	printer(Tprint &value)
{
	std::cout << value << std::endl;
}

template<typename Titer>
void	iter(Titer *array, size_t len, void (*function)( const Titer &elem))
{
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}

#endif