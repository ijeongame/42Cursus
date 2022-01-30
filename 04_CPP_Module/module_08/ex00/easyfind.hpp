/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:08:09 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/30 14:51:40 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

class FindException : public std::exception{
	public :
		const char* what() const throw() {
			return ("Not Found Value");
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator itr = std::find(container.begin(), container.end(), value);
	if (itr == container.end())
		throw FindException();
	return (itr);
}

#endif
