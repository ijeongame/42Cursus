/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:58:56 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/21 01:41:42 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("", 0, 0)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: Form("ShrubberyCreationForm", 145, 137)
{
	setTarget(target);
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & sh)
	: Form(sh)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & sh)
{
	this->Form::operator=(sh);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const &bu) const
{
	executeCheck(bu);
	std::ofstream fout("_shrubbery");
	if (!fout.is_open() || !fout.good())
		throw std::ofstream::failure("Cannot open file" + this->getTarget() + "_Shrubbery");
	fout << "       /\\       " << std::endl;
	fout << "      /\\*\\      " << std::endl;
	fout << "     /\\O\\*\\     " << std::endl;
	fout << "    /*/\\/\\/\\    " << std::endl;
	fout << "   /\\O\\/\\*\\/\\   " << std::endl;
	fout << "  /\\*\\/\\*\\/\\/\\  " << std::endl;
	fout << " /\\O\\/\\/*/\\/O/\\ " << std::endl;
	fout << "       ||       " << std::endl;
	fout << "       ||       " << std::endl;
	fout << "       ||       " << std::endl;
	fout << "     ======     " << std::endl;
	fout.close();
}
