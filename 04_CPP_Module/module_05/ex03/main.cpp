/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:44:37 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 15:38:41 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat hkwon("hkwon", 1);
	Bureaucrat wrong("wrong", 150);
	Intern intern;

	Form *form;

	form = intern.makeForm("ShrubberyCreation", "target");
	hkwon.executeForm(*form);
	hkwon.signForm(*form);
	wrong.executeForm(*form);
	wrong.executeForm(*form);
	delete form;

	std::cout << std::endl;
	form = intern.makeForm("RobotomyRequest", "target");
	hkwon.executeForm(*form);
	hkwon.signForm(*form);
	wrong.executeForm(*form);
	wrong.executeForm(*form);
	delete form;

	std::cout << std::endl;
	form = intern.makeForm("PresidentialPardon", "target");
	hkwon.executeForm(*form);
	hkwon.signForm(*form);
	wrong.executeForm(*form);
	wrong.executeForm(*form);
	delete form;

	try
	{
		form = intern.makeForm("WrongName", "target");
		hkwon.executeForm(*form);
		hkwon.signForm(*form);
		wrong.executeForm(*form);
		wrong.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
