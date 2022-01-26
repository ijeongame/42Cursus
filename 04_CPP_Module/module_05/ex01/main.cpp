/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 21:44:37 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 16:24:37 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// int main(void)
// {
// 	Bureaucrat a("Bure_A", 10);
// 	Bureaucrat b("Bure_B", 75);
// 	Bureaucrat c("Bure_C", 150);

// 	Form test10("test_10", 10, 5);
// 	Form test75("test_75", 75, 70);
// 	Form test150("test_150", 150, 145);

// 	std::cout << test10 << std::endl;
// 	std::cout << test75 << std::endl;
// 	std::cout << test150 << std::endl;
// 	std::cout << std::endl;
// 	try
// 	{
// 		a.signForm(test10);
// 		a.signForm(test75);
// 		a.signForm(test150);
// 	}
// 	catch(std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
// 	try
// 	{
// 		b.signForm(test10);
// 		b.signForm(test75);
// 		b.signForm(test150);
// 	}
// 	catch(std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
// 	try
// 	{
// 		test75.beSigned(c);
// 	}
// 	catch(std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	return (0);
// }
void f_make(const std::string& name,
            const int& sign_grade,
            const int& exec_grade) {
  try {
    Form  f(name, sign_grade, exec_grade);
    std::cout << f << std::endl;
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
}

int main(void) {
  Bureaucrat  j("Jseo", 1);
  Bureaucrat  h("Hyson", 75);
  Form  f1("f1", 30, 30);
  Form  f2(f1);
  Form  f3("f3", 75, 50);

  std::cout << f1 << std::endl
    << f2 << std::endl
    << f3 << std::endl;
  std::cout << std::endl;
  h.signForm(f1);
  j.signForm(f2);
  h.signForm(f3);
  std::cout << std::endl;
  std::cout << f1 << std::endl
    << f2 << std::endl
    << f3 << std::endl;
  std::cout << std::endl;
  f_make("f4", 0, 50);
  f_make("f5", 50, 0);
  f_make("f6", 151, 50);
  f_make("f7", 50, 151);
  return 0;
}
