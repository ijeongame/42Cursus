/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:22:42 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 23:44:25 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name(""), sign_grade(0), exec_grade(0) {}

Form::Form(const std::string &_name, const int &_sign_grade, const int &_exec_grade)
	: name(_name), sign_grade(_sign_grade), exec_grade(_exec_grade), is_signed(false)
{
	if (sign_grade < HIGHEST || exec_grade < HIGHEST)
		throw GradeTooHighException();
	if (sign_grade > LOWEST || exec_grade > LOWEST)
		throw GradeTooLowException();
}

Form::Form(Form const &f)
	: name(f.getName()), sign_grade(f.getSignGrade()), exec_grade(f.getExecGrade()), is_signed(false)
{
	if (sign_grade < HIGHEST || exec_grade < HIGHEST)
		throw GradeTooHighException();
	if (sign_grade > LOWEST || exec_grade > LOWEST)
		throw GradeTooLowException();
}

Form & Form::operator=(Form const &f)
{
	if (this != &f)
	{
		*(const_cast<std::string*>(&name)) = f.getName();
		*(const_cast<int*>(&sign_grade)) = f.getSignGrade();
		*(const_cast<int*>(&exec_grade)) = f.getExecGrade();
		is_signed = f.getSign();
	}
	return (*this);
}

Form::~Form(void) {}

const std::string &Form::getName(void) const
{
	return (name);
}

bool Form::getSign(void) const
{
	return (is_signed);
}

const int &Form::getSignGrade(void) const
{
	return (sign_grade);
}

const int &Form::getExecGrade(void) const
{
	return (exec_grade);
}

void	Form::beSigned(const Bureaucrat& bu)
{
	if (bu.getGrade() <= getSignGrade())
		is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream&	operator<<(std::ostream& o, const Form& f)
{
	o << "<" << f.getName() << ">, sign grade <" << f.getSignGrade() << ">, exec grade <" << f.getExecGrade() << ">";
	if (f.getSign())
		o << ", <signed>";
	else
		o << ", <not signed>";
	return (o);
}
