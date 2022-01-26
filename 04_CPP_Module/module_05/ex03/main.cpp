/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:44:37 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/27 00:15:05 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat bu1("bu1", 1);
	Bureaucrat bu2("bu3", 140);

	Form* f1 = new ShrubberyCreationForm("First");
	Form* f2 = new RobotomyRequestForm("Second");
	Form* f3 = new PresidentialPardonForm("Third");

	std::cout << bu1 << std::endl
		<< bu2 << std::endl;

	std::cout << std::endl;
	std::cout << *f1 << std::endl
		<< *f2 << std::endl
		<< *f3 << std::endl;

	std::cout << std::endl;
	bu1.signForm(*f1);
	bu1.signForm(*f2);
	bu1.signForm(*f3);

	std::cout << std::endl;
	bu1.executeForm(*f1);
	bu1.executeForm(*f2);
	bu1.executeForm(*f3);

	std::cout << std::endl;
	bu2.signForm(*f1);
	bu2.signForm(*f2);
	bu2.signForm(*f3);

	std::cout << std::endl;
	bu2.executeForm(*f1);
	bu2.executeForm(*f2);
	bu2.executeForm(*f3);

	delete f3;
	delete f2;
	delete f1;
	return (0);
}
