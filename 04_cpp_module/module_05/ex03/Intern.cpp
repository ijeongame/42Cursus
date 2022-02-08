/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:03:02 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/26 16:03:11 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(const Intern& i)
{
	*this = i;
}

Intern& Intern::operator=(const Intern& i)
{
	(void)(i);
	return (*this);
}

Form *Intern::makeForm(const std::string & name, const std::string & target)
{
	std::string form[3] = {"ShrubberyCreation", "RobotomyRequest", "PresidentialPardon"};
	try
	{
		for(int i = 0; i < 3 ; ++i)
		{
			if (form[i] == name)
			{
				std::cout << "Intern creates <" << name << "> " << std::endl;
				switch(i)
				{
					case 0:
						return (new ShrubberyCreationForm(target));
						break;
					case 1:
						return (new RobotomyRequestForm(target));
						break;
					case 2:
						return (new PresidentialPardonForm(target));
						break;
				}
			}
		}
		throw NoNameFormException();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return NULL;
	}

}
