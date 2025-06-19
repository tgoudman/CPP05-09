#include "include/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : mData(other.mData), mDeq(other.mDeq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		mData = other.mData;
		mDeq = other.mDeq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::setData(const std::vector<int>& data)
{
	mData = data;
}

void PmergeMe::setDeq(const std::deque<int>& deq)
{
	mDeq = deq;
}

std::vector<int>& PmergeMe::getData()
{
	return mData;
}

std::deque<int>& PmergeMe::getDeq()
{
	return mDeq;
}