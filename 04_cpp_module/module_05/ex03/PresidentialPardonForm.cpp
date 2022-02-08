/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 01:32:51 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 16:38:32 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("", 0, 0)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: Form(target, 25, 5)
{
	setTarget("PresidentialPardonForm");
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & pr)
	: Form(pr)
{
	setTarget("PresidentialPardonForm");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & pr)
{
	Form::operator=(pr);
	setTarget(pr.getTarget());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void	PresidentialPardonForm::execute(Bureaucrat const &bu) const
{
	executeCheck(bu);
	std::cout << "<" << getName() << ">" << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
