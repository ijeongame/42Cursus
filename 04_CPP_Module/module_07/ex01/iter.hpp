/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:12:58 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/28 15:41:07 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T1, typename T2>
void iter(T1* lst, T2 len, void (* f)(T1 &))
{
	for(T2 i = 0; i < len; i++)
		f(lst[i]);
}

template <typename T>
void print(T &val)
{
	std::cout << val << std::endl;
}

template <typename T>
void printAdd(T &val)
{
	val += 1;
}

#endif
