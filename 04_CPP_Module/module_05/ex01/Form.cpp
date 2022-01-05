/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:22:42 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/21 01:12:09 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : sign_grade(0), exec_garde(0) {}

Form::Form(const std::string &_name, const int &_sign_grade, const int &_exec_grade)
	: name(_name), sign_grade(_sign_grade), exec_garde(_exec_grade), is_signed(false)
{
	if (sign_grade < HIGHEST || exec_garde < HIGHEST)
		throw GradeTooHighException();
	if (sign_grade > LOWEST || exec_garde > LOWEST)
		throw GradeTooLowException();
}

Form::Form(Form const &f)
	: name(f.getName()), sign_grade(f.getSignGrade()), exec_garde(f.getExecGrade()), is_signed(false)
{
	if (sign_grade < HIGHEST || exec_garde < HIGHEST)
		throw GradeTooHighException();
	if (sign_grade > LOWEST || exec_garde > LOWEST)
		throw GradeTooLowException();
}

Form & Form::operator=(Form const &f)
{
	if (this != &f)
		this->is_signed = f.getSign();
	return (*this);
}

Form::~Form(void) {}

std::string const &Form::getName(void) const
{
	return (name);
}

bool Form::getSign(void) const
{
	return (is_signed);
}

int Form::getSignGrade(void) const
{
	return (sign_grade);
}

int Form::getExecGrade(void) const
{
	return (exec_garde);
}

void	Form::beSigned(const Bureaucrat& bu)
{
	if (bu.getGrade() < sign_grade)
		is_signed = true;
	else
		throw GradeTooHighException();
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Form Grade Too High");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Form Grade Too Low");
}

std::ostream&	operator<<(std::ostream& o, const Form& f)
{
	o << "<" << f.getName() << ">, sign grade <" << f.getSignGrade() << ">, exec grade <" << f.getExecGrade() << ">";
	if (f.getSign())
		o << ", signed" << std::endl;
	else
		o << ", not signed" << std::endl;
	return (o);
}
