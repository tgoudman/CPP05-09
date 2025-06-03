/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoudman <tgoudman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:02:45 by nezumickey        #+#    #+#             */
/*   Updated: 2025/06/03 10:45:33 by tgoudman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::nbr_compare = 0;

//_________________________________  Constructor  ______________________________

PmergeMe::PmergeMe()
{
	std::cout << "Default PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
	std::cout << "Copy PmergeMe constructor called" << std::endl;
}

//_________________________________  Destructor  _______________________________

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

//__________________________________  Operator  ________________________________

PmergeMe	&PmergeMe::operator=(const PmergeMe &other)
{
	std::cout << "PmergeMe copy assignment operator called" << std::endl;
	if (this != &other)
	{
	}
	return *this;
}

//______________________________  Member Functions  ____________________________

long PmergeMe::jacobsthal_number(long n) 
{
	return round((pow(2, n + 1) + pow(-1, n)) / 3); 
}

void PmergeMe::sort_vec(std::vector<int>& vec) 
{
	_insertion_sort<std::vector<int> >(vec, 1); 
}

void PmergeMe::sort_deque(std::deque<int>& deque)
{
	_insertion_sort<std::deque<int> >(deque, 1);
}

int PmergeMe::F(int n)
{
	int result = 0;
	for (int k = 1; k <= n; ++k)
	{
		double value = (3.0 / 4.0) * k;
		std::cout << "-----------" << std::endl;
		std::cout << "value: " << value << std::endl; 
		result = static_cast<int>(ceil(log2(value)));
		std::cout << "result: " << result << std::endl;
		// std::cout << "-----------" << std::endl;
	}
	return (result);
}

template <typename T> 
bool compare(T it, T itNext)
{
	PmergeMe::nbr_compare++;
	return (*it < *itNext);
};

template <typename T> T next(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template <typename T>
void 	PmergeMe::_swap_pair(T it, int pair_level)
{
	T start = next(it, -pair_level + 1);
	T end = next(it, pair_level);
	while (start != end)
	{
		std::iter_swap(start, next(start, pair_level));
		start++;
	}
}

template <typename T>
void	PmergeMe::_insertion_sort(T& container, int pair_level)
{
	typedef typename T::iterator Iterator;

    int pair_units_nbr = container.size() / pair_level;
    if (pair_units_nbr < 2)
        return;

    /* If there is an odd pair, we ignore it during swapping.
       It will go to the pend as the last pair. */
    bool is_odd = pair_units_nbr % 2 == 1;
	Iterator start = container.begin();
    Iterator last = next(container.begin(), pair_level * (pair_units_nbr));
    Iterator end = next(last, -(is_odd * pair_level));
	    int jump = 2 * pair_level;
    for (Iterator it = start; it != end; std::advance(it, jump))
    {
        Iterator this_pair = next(it, pair_level - 1);
        Iterator next_pair = next(it, pair_level * 2 - 1);
        if (compare(next_pair, this_pair))
        {
            _swap_pair(this_pair, pair_level);
        }
    }
    _insertion_sort(container, pair_level * 2);

    /* Main contains an already sorted sequence.
       Pend stores a yet to be sorted numbers.
       List data structure for quick random insertion and deletion.
       They contain iterators instead of the numbers themselves because
       iterators + pair_level contain all the information about the stored
       ranges of numbers. */
    std::vector<Iterator> main;
    std::vector<Iterator> pend;

    /* Initialize the main chain with the {b1, a1}. */
    main.insert(main.end(), next(container.begin(), pair_level - 1));
    main.insert(main.end(), next(container.begin(), pair_level * 2 - 1));

    /* Insert the rest of a's into the main chain.
       Insert the rest of b's into the pend. */
    for (int i = 4; i <= pair_units_nbr; i += 2)
    {
        pend.insert(pend.end(), next(container.begin(), pair_level * (i - 1) - 1));
        main.insert(main.end(), next(container.begin(), pair_level * i - 1));
    }

    /* Insert an odd element to the pend, if there are any. */
    if (is_odd)
    {
        pend.insert(pend.end(), next(end, pair_level - 1));
    }

    /* Insert the pend into the main in the order determined by the
       Jacobsthal numbers. For example: 3 2 -> 5 4 -> 11 10 9 8 7 6 -> etc.
       During insertion, main numbers serve as an upper bound for inserting numbers,
       in order to save number of comparisons, as we know already that, for example,
       b5 is lesser than a5, we binary search only until a5, not until the end
       of the container.
           We can calculate the index of the bound element. With the way I do it,
           the index of the bound is inserted_numbers + current_jacobsthal_number. */
    int prev_jacobsthal = jacobsthal_number(1);
    int inserted_numbers = 0;
    for (int k = 2;; k++)
    {
        int curr_jacobsthal = jacobsthal_number(k);
        int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
		int offset = 0;
        if (jacobsthal_diff > static_cast<int>(pend.size()))
            break;
        int nbr_of_times = jacobsthal_diff;
        typename std::vector<Iterator>::iterator pend_it = next(pend.begin(), jacobsthal_diff - 1);
        typename std::vector<Iterator>::iterator bound_it =
            next(main.begin(), curr_jacobsthal + inserted_numbers);
        while (nbr_of_times)
        {
            typename std::vector<Iterator>::iterator idx =
                std::upper_bound(main.begin(), bound_it, *pend_it, compare<Iterator>);
            typename std::vector<Iterator>::iterator inserted = main.insert(idx, *pend_it);
            nbr_of_times--;
            pend_it = pend.erase(pend_it);
            std::advance(pend_it, -1);
            /* Sometimes the inserted number in inserted at the exact index of where the bound should be.
			   When this happens, it eclipses the bound of the next pend, and it does more comparisons
			   than it should. We need to offset when this happens. */
            offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
			bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
        }
        prev_jacobsthal = curr_jacobsthal;
        inserted_numbers += jacobsthal_diff;
		offset = 0;
    }

    /* Insert the remaining elements in the reversed order. Here we also want to
       perform as less comparisons as possible, so we calculate the starting bound
       to insert pend number to be the pair of the first pend number. If the first
       pend number is b8, the bound is a8, if the pend number is b7, the bound is a7 etc.
       With the way I do it the index of bound is
       size_of_main - size_of_pend + index_of_current_pend. */
    for (ssize_t i = pend.size() - 1; i >= 0; i--)
    {
        typename std::vector<Iterator>::iterator curr_pend = next(pend.begin(), i);
        typename std::vector<Iterator>::iterator curr_bound =
            next(main.begin(), main.size() - pend.size() + i + is_odd);
        typename std::vector<Iterator>::iterator idx =
            std::upper_bound(main.begin(), curr_bound, *curr_pend, compare<Iterator>);
        main.insert(idx, *curr_pend);
    }

    /* Use copy vector to store all the numbers, in order not to overwrite the
       original iterators. */
    std::vector<int> copy;
    copy.reserve(container.size());
    for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++)
    {
        for (int i = 0; i < pair_level; i++)
        {
            Iterator pair_start = *it;
            std::advance(pair_start, -pair_level + i + 1);
            copy.insert(copy.end(), *pair_start);
        }
    }

    /* Replace values in the original container. */
    Iterator container_it = container.begin();
    std::vector<int>::iterator copy_it = copy.begin();
    while (copy_it != copy.end())
    {
        *container_it = *copy_it;
        container_it++;
        copy_it++;
    }
}

