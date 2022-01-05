/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 01:16:33 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/20 21:19:53 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {}


Bureaucrat::Bureaucrat(std::string const & _name, int _grade)
	: name(_name)
{
	this->grade = _grade;
	if (this->grade < HIGHEST)
		throw GradeTooHighException();
	if (this->grade > LOWEST)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &bu) : name(bu.getName())
{
	this->grade = bu.getGrade();
	if (this->grade < HIGHEST)
		throw GradeTooHighException();
	if (this->grade > LOWEST)
		throw GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bu)
{
	if (this != &bu)
		this->grade = bu.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

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

const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat Grade Too High");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat Grade Too Low");
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& bu)
{
	return (o << "<" << bu.getName() << ">, bureaucrat grade <" << bu.getGrade() << ">." << std::endl);
}
