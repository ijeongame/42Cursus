/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:58:08 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/29 19:36:00 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	for(int i = 0; i < 10; i++)
	{
		v.push_back(i);
		d.push_back(i);
		l.push_back(i);
	}

	//print
	std::cout << "vector" << std::endl;
	for (int i = 0; i < (int)v.size(); i++)
		std::cout << v[i] << ' ';
	std::cout << std::endl;
	std::cout << "deque" << std::endl;
	for (int i = 0; i < (int)d.size(); i++)
		std::cout << d[i] << ' ';
	std::cout << std::endl;
	std::cout << "list" << std::endl;
	std::list<int>::iterator itr;
	for (itr = l.begin(); itr != l.end(); itr++)
		std::cout << *itr << ' ';
	std::cout << std::endl;

	//find
	std::cout << std::endl;
	std::cout << "find in vector" << std::endl;
	try{
		std::vector<int>::iterator itr = easyfind(v, 3);
		std::cout << "value <" << *itr << "> find" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "find in deque" << std::endl;
	try{
		std::deque<int>::iterator itr = easyfind(d, 7);
		std::cout << "value <" << *itr << "> find" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "find in list" << std::endl;
	try{
		std::list<int>::iterator itr = easyfind(l, 10);
		std::cout << "value <" << *itr << "> find" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
