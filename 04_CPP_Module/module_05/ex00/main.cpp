/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 02:12:33 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/24 22:52:52 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat test1("test", 151);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat test2("test", 0);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat test3("test3", 1);
	Bureaucrat test4("test4", 150);
	std::cout << test3;
	std::cout << test4;
	try
	{
		test3.increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		test4.decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
