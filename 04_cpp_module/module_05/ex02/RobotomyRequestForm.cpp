/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:25:02 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 18:00:25 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("", 0, 0)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: Form(target, 72, 45)
{
	setTarget("RobotomyRequestForm");
}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & ro)
	: Form(ro)
{
	setTarget("RobotomyRequestForm");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & ro)
{
	Form::operator=(ro);
	setTarget(ro.getTarget());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void	RobotomyRequestForm::execute(Bureaucrat const &bu) const
{
	executeCheck(bu);
	srand(time(NULL));
	if (rand() % 2 == 0)
	{
		std::cout << "drrrrrrrrrrrr" << std::endl;
		std::cout << "<" << bu.getName() << ">" << " robotomized succes" << std::endl;
	}
	else
		std::cout << "<" << bu.getName() << ">" << " robotomized fail" << std::endl;
}
