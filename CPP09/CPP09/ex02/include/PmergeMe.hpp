/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nezumickey <nezumickey@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:02:38 by nezumickey        #+#    #+#             */
/*   Updated: 2025/06/16 21:05:53 by nezumickey       ###   ########.fr       */
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
#include <climits>
#include <sstream>
#include <ctime>
# include "color.hpp"

class PmergeMe
{
	public:
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		PmergeMe();

		void setData(const std::vector<int>& data);
		void setDeq(const std::deque<int>& deq);
		std::vector<int>& getData();
		std::deque<int>& getDeq();

	private:
		std::vector<int> mData;
		std::deque<int> mDeq;
};

#include "../PmergeMe.tpp"

#endif