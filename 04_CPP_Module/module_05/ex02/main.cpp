/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:44:37 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 16:26:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// int main(void)
// {
// 	Bureaucrat a("Bure_A", 5);
// 	Bureaucrat b("Bure_B", 75);
// 	Bureaucrat c("Bure_C", 150);

// 	ShrubberyCreationForm shr("shrubbery");
// 	RobotomyRequestForm rob("roboto");
// 	PresidentialPardonForm pre("president");

// 	std::cout << std::endl;
// 	try
// 	{
// 		a.executeForm(shr);
// 	}
// 	catch(std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	std::cout << std::endl;
// 	a.signForm(shr);
// 	a.signForm(rob);
// 	a.signForm(pre);
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// 	try
// 	{
// 		a.executeForm(shr);
// 		a.executeForm(rob);
// 		a.executeForm(pre);
// 	}
// 	catch(std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
// 	std::cout << std::endl;
// 	try
// 	{
// 		b.executeForm(shr);
// 		b.executeForm(rob);
// 	}
// 	catch(std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	std::cout << std::endl;
// 	try
// 	{
// 		c.executeForm(shr);
// 	}
// 	catch(std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	return 0;
// }
int main(void) {
  Bureaucrat b1("Admin", 1);
  Bureaucrat b2("Jseo", 15);
  Bureaucrat b3("Dohykim", 70);
  Bureaucrat b4("Hyson", 140);

  Form*f1 = new PresidentialPardonForm("Chang Chen");
  Form*f2 = new RobotomyRequestForm("Terminator");
  Form*f3 = new ShrubberyCreationForm("Fangorn");

  std::cout << b1 << std::endl
    << b2 << std::endl
    << b3 << std::endl
    << b4 << std::endl;
  std::cout << std::endl;
  std::cout << *f1 << std::endl
    << *f2 << std::endl
    << *f3 << std::endl;
  std::cout << std::endl;
  b2.signForm(*f1);
  b3.signForm(*f2);
  b4.signForm(*f3);
  std::cout << std::endl;
  b2.executeForm(*f1);
  b3.executeForm(*f2);
  b4.executeForm(*f3);
  std::cout << std::endl;
  b1.executeForm(*f1);
  b1.executeForm(*f2);
  b1.executeForm(*f3);

  delete f3;
  delete f2;
  delete f1;
  return 0;
}
