/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:25:02 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/20 16:15:54 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

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
	if (rand() % 2 == 0)
		std::cout << bu.getName() << "robotomized succes" << std::endl;
	else
		std::cout << bu.getName() << "robotomized fail" << std::endl;
}
