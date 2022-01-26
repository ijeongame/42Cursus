/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:44:37 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 16:26:39 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// int main()
// {
// 	Bureaucrat hkwon("hkwon", 1);
// 	Bureaucrat wrong("wrong", 150);
// 	Intern intern;

// 	Form *form;

// 	form = intern.makeForm("ShrubberyCreation", "target");
// 	hkwon.executeForm(*form);
// 	hkwon.signForm(*form);
// 	wrong.executeForm(*form);
// 	wrong.executeForm(*form);
// 	delete form;

// 	std::cout << std::endl;
// 	form = intern.makeForm("RobotomyRequest", "target");
// 	hkwon.executeForm(*form);
// 	hkwon.signForm(*form);
// 	wrong.executeForm(*form);
// 	wrong.executeForm(*form);
// 	delete form;

// 	std::cout << std::endl;
// 	form = intern.makeForm("PresidentialPardon", "target");
// 	hkwon.executeForm(*form);
// 	hkwon.signForm(*form);
// 	wrong.executeForm(*form);
// 	wrong.executeForm(*form);
// 	delete form;

// 	try
// 	{
// 		form = intern.makeForm("WrongName", "target");
// 		hkwon.executeForm(*form);
// 		hkwon.signForm(*form);
// 		wrong.executeForm(*form);
// 		wrong.executeForm(*form);
// 		delete form;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return 0;
// }
int main(void) {
  Intern i;
  Bureaucrat b1("Admin", 1);
  Bureaucrat b2("Jseo", 15);
  Bureaucrat b3("Dohykim", 70);
  Bureaucrat b4("Hyson", 140);

  Form* f1 = i.makeForm(P_FORM, "Chang Chen");
  Form* f2 = i.makeForm(R_FORM, "Terminator");
  Form* f3 = i.makeForm(S_FORM, "Fangorn");
  i.makeForm("Something Wrong", "NOT GONNAE GENERATED");

  if (!f1 || !f2 || !f3)
    return (1);
  std::cout << std::endl;
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
