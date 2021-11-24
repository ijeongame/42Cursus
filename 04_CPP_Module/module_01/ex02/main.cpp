/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:41:29 by hkwon             #+#    #+#             */
/*   Updated: 2021/11/24 17:40:34 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = std::string("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address str : " << &str << std::endl
		<< "Address ptr : " << stringPTR << std::endl
		<< "Address ref : " << &stringREF << std::endl;
	std::cout << "str using " << "ptr : " << *stringPTR
		<< ", ref : " << stringREF << std::endl;
}
