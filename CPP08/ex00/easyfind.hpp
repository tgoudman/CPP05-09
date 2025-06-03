/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:08:20 by tgoudman          #+#    #+#             */
/*   Updated: 2025/05/27 15:47:25 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>
# include "color.hpp"
# include <vector>
# include <string>
# include <cstdlib>
# include <ctime> 
# include <deque>
# include <queue>
# include <list>

class notExceptionFound : public std::exception
{

	public:
		virtual const char *what() const throw()
		{
			return ("Element not found");
		}
	};

template<typename T>
int easyfind(T container , int nb)
{
	typename T::iterator it = std::find(container.begin(), container.end(), nb);
	if (it == container.end())
		throw notExceptionFound();
	return *it;
}


#endif