/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:41:29 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/04 22:39:36 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = std::string("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Print Address" << std::endl;
	std::cout << "Address str : " << &str << std::endl
		<< "Address ptr : " << stringPTR << std::endl
		<< "Address ref : " << &stringREF << std::endl;

	std::cout << std::endl << "Print String" << std::endl;
	std::cout << "str using ptr : " << *stringPTR << std::endl
		<< "str using ref : " << stringREF << std::endl;
}
