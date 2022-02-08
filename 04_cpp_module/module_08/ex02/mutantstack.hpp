/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:07:40 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/30 17:04:35 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack() {}
		MutantStack(MutantStack const &ms) { *this = ms; }
		~MutantStack() {}
		MutantStack<T> &operator=(MutantStack const &ms){
			if (this != &ms)
				std::stack<T>::operator=(ms);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		//c++11
		// typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		// typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}

		reverse_iterator rbegin()
		{
			return (this->c.rbegin());
		}
		reverse_iterator rend()
		{
			return (this->c.rend());
		}

		//c++11
		// const_iterator cbegin() const
		// {
		// 	return (this->c.cbegin());
		// }
		// const_iterator cend() const
		// {
		// 	return (this->c.cend());
		// }

		// const_reverse_iterator crbegin() const
		// {
		// 	return (this->c.crbegin());
		// }
		// const_reverse_iterator crend() const
		// {
		// 	return (this->c.crend());
		// }
};

#endif
