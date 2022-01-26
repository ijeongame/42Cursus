/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:44:37 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 15:26:59 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat a("Bure_A", 5);
	Bureaucrat b("Bure_B", 75);
	Bureaucrat c("Bure_C", 150);

	ShrubberyCreationForm shr("shrubbery");
	RobotomyRequestForm rob("roboto");
	PresidentialPardonForm pre("president");

	std::cout << std::endl;
	try
	{
		a.executeForm(shr);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	a.signForm(shr);
	a.signForm(rob);
	a.signForm(pre);
	std::cout << std::endl;
	std::cout << std::endl;
	try
	{
		a.executeForm(shr);
		a.executeForm(rob);
		a.executeForm(pre);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	try
	{
		b.executeForm(shr);
		b.executeForm(rob);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	try
	{
		c.executeForm(shr);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
