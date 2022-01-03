/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:41:29 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 17:40:34 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 19:27:57 by hkwon            ###   ########.fr       */
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
<<<<<<< HEAD
=======
#include <string>
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400

int main(void)
{
	std::string str = std::string("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string &stringREF = str;

<<<<<<< HEAD
	std::cout << "Address str : " << &str << std::endl
		<< "Address ptr : " << stringPTR << std::endl
		<< "Address ref : " << &stringREF << std::endl;
	std::cout << "str using " << "ptr : " << *stringPTR
		<< ", ref : " << stringREF << std::endl;
=======
	std::cout << "Print Address" << std::endl;
	std::cout << "Address str : " << &str << std::endl
		<< "Address ptr : " << stringPTR << std::endl
		<< "Address ref : " << &stringREF << std::endl;

	std::cout << std::endl << "Print String" << std::endl;
	std::cout << "str using ptr : " << *stringPTR << std::endl
		<< "str using ref : " << stringREF << std::endl;
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
}
