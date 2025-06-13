/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:02:38 by nezumickey        #+#    #+#             */
/*   Updated: 2025/06/10 00:45:29 by nezumickey       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstring>
# include <cstdlib>
# include <time.h>
# include <iomanip>
# include <cmath>
# include <algorithm>
# include "color.hpp"

class PmergeMe
{
	private:
		template <typename T>void	_insertion_sort(T& container, int pair_level);
		template <typename T>void 	_swap_pair(T it, int pair_level);

	public:
		static int 					nbr_compare;
		// Constructeur
		PmergeMe();
		PmergeMe(const PmergeMe &other);

		// Overloading Operateur
		PmergeMe &operator=(const PmergeMe &other);

		// Destructor
		~PmergeMe();

		// Member Functions
		int 	F(int n);
	    void	sort_vec(std::vector<int>& vec);
   		void	sort_deque(std::deque<int>& deque);
		long 	jacobsthalNumber(long n);
};


#endif