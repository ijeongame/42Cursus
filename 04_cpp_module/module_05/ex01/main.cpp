/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:44:37 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/27 00:36:28 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void) {
	Bureaucrat	bu1("bu1", 1);
	Bureaucrat	bu2("bu2", 75);
	Form		f1("f1", 30, 30);
	Form		f2("f2", 75, 50);

	std::cout << f1 << std::endl
		<< f2 << std::endl;
	std::cout << std::endl;
	bu1.signForm(f1);
	bu1.signForm(f2);

	std::cout << std::endl;
	bu2.signForm(f1);
	bu2.signForm(f2);

	std::cout << std::endl;
	try
	{
		Form f3("f3", 0, 50);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form f4("f4", 50, 0);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form f5("f5", 151, 50);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form f6("f6", 50, 151);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
