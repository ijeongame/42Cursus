/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:51:52 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/29 23:48:58 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(void)
{
	_vec.reserve(0);
}

Span::~Span(void){}

Span::Span(unsigned int n)
{
	_vec.reserve(n);
}

Span::Span(const Span& s)
{
	_vec = s.getData();
}

Span& Span::operator=(const Span& s)
{
	if (this != &s)
		this->_vec = s.getData();
	return (*this);
}

const std::vector<int>& Span::getData(void) const {
  return _vec;
}

void Span::addNumber(int value)
{
	if (_vec.size() == _vec.capacity())
		throw StoreException();
	_vec.push_back(value);
}

void Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end)
{
	std::vector<int>::iterator itr = begin;

	for (; itr != end; itr++)
	{
		if (_vec.size() == _vec.capacity())
			throw StoreException();
		_vec.push_back(*itr);
	}
}

int Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw FindException();
	std::vector<int> _copy(_vec);
	sort(_copy.begin(), _copy.end());
	std::vector<int>::iterator itr = _copy.begin();
	int min = *(itr + 1) - *itr;
	for (; itr != _copy.end() - 1; itr++)
	{
		if (*(itr + 1) - *itr < min)
			min = *(itr + 1) - *itr;
	}
	return (min);

	// #include <numeric>

	// class Functor {
	//  public:
	//   int operator()(const int& i) { return std::abs(i); }
	// };

	// std::adjacent_difference(_copy.begin(), _copy.end(), _copy.begin());
	// for(int i = 0; i < (int)_copy.size(); i++)
	// 	std::cout << "diff : " << _copy[i] << std::endl;
	// std::transform(_copy.begin(), _copy.end(), _copy.begin(), Functor());
	// return *std::min_element(_copy.begin(), _copy.end());
}

int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw FindException();
	int max = *max_element(_vec.begin(), _vec.end());
	int min = *min_element(_vec.begin(), _vec.end());
	return (max - min);
}
