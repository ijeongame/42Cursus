/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 01:16:33 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/27 00:16:25 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) {}


Bureaucrat::Bureaucrat(std::string const & _name, int _grade)
	: name(_name)
{
	grade = _grade;
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

void	Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << "<" << name << ">" << " signs "
			<< "<" << f.getName() << ">" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "<" << name << ">" << " cannot sign "
			<< "<" << f.getName() << ">" << " because <" << e.what() << ">" << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const &f)
{
	try
	{
		f.execute(*this);
		std::cout << "<" << name << ">" << " executes "
			<< "<" << f.getName() << ">" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "<" << name << ">" << " cannot executes "
			<< "<" << f.getName() << ">" << " because <" << e.what() << ">" << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& bu)
{
	return (o << "<" << bu.getName() << ">, bureaucrat grade <" << bu.getGrade() << ">.");
}
