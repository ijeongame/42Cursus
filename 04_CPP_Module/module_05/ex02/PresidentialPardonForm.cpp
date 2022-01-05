/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:32:51 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/21 01:43:07 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("", 0, 0)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: Form("PresidentialPardonForm", 72, 45)
{
	setTarget(target);
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & pr)
	: Form(pr)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & pr)
{
	this->Form::operator=(pr);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void	PresidentialPardonForm::execute(Bureaucrat const &bu) const
{
	executeCheck(bu);
	std::cout << bu.getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
