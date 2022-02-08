/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 01:16:33 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/27 13:37:52 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string const & _name, int _grade)
	: name(_name)
{
	grade = _grade;
	std::cout << "constructor" << std::endl;
	if (grade < HIGHEST)
		throw GradeTooHighException();
	if (grade > LOWEST)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &bu) : name(bu.getName())
{
	grade = bu.getGrade();
	if (grade < HIGHEST)
		throw GradeTooHighException();
	if (grade > LOWEST)
		throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bu)
{
	if (this != &bu)
	{
		*(const_cast<std::string*>(&name)) = bu.getName();
		grade = bu.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "destructor" << std::endl;
}

std::string const & Bureaucrat::getName() const
{
	return (name);
}

int	Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::increaseGrade(void)
{
	if (grade - 1 < HIGHEST)
		throw GradeTooHighException();
	else
		--grade;
}

void Bureaucrat::decreaseGrade(void)
{
	if (grade + 1 > LOWEST)
		throw GradeTooLowException();
	else
		++grade;
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& bu)
{
	return (o << "<" << bu.getName() << ">, bureaucrat grade <" << bu.getGrade() << ">.");
}
