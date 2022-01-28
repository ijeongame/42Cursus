/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:13:01 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/28 15:42:10 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	char a[5] = {'a', 'b', 'c', 'd', 'e'};
	int b[6] = {1, 2, 3, 4, 5, 6};
	double c[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
	std::string d[4] = {"hkwon", "seoul", "busan", "42"};

	std::cout << "Test iter type <char>" << std::endl;
	iter(a, sizeof(a)/sizeof(*a), print);
	std::cout << std::endl;

	std::cout << "Test iter type <int>" << std::endl;
	iter(b, sizeof(b)/sizeof(*b), print);
	std::cout << std::endl;
	iter(b, sizeof(b)/sizeof(*b), printAdd);
	iter(b, sizeof(b)/sizeof(*b), print);
	std::cout << std::endl;

	std::cout << "Test iter type <double>" << std::endl;
	iter(c, sizeof(c)/sizeof(*c), print);
	std::cout << std::endl;
	iter(c, sizeof(c)/sizeof(*c), printAdd);
	iter(c, sizeof(c)/sizeof(*c), print);
	std::cout << std::endl;

	std::cout << "Test iter type <std::string>" << std::endl;
	iter(d, sizeof(d)/sizeof(*d), print);
}
