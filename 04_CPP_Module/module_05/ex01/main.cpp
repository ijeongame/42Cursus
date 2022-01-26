/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:44:37 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 15:20:51 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
	Bureaucrat a("Bure_A", 10);
	Bureaucrat b("Bure_B", 75);
	Bureaucrat c("Bure_C", 150);

	Form test10("test_10", 10, 5);
	Form test75("test_75", 75, 70);
	Form test150("test_150", 150, 145);

	std::cout << test10 << std::endl;
	std::cout << test75 << std::endl;
	std::cout << test150 << std::endl;
	std::cout << std::endl;
	try
	{
		a.signForm(test10);
		a.signForm(test75);
		a.signForm(test150);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		b.signForm(test10);
		b.signForm(test75);
		b.signForm(test150);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		test75.beSigned(c);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
