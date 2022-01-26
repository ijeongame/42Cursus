/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 02:12:33 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 17:48:08 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bu1("bu1", 151);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bu2("bu2", 0);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	Bureaucrat bu3("bu3", 1);
	Bureaucrat bu4("bu4", 150);
	std::cout << bu3 << std::endl;
	std::cout << bu4 << std::endl;
	try
	{
		bu3.increaseGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		bu4.decreaseGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
