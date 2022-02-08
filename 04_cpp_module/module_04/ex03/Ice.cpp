/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:19:13 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/22 16:55:11 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Default Constructor Ice" << std::endl;
}

Ice::Ice(std::string const type) : AMateria(type)
{
	std::cout << "Named Constructor Ice" << std::endl;
}

Ice::Ice(Ice const &ic) : AMateria(ic.getType())
{
}

Ice	&Ice::operator=(Ice const &ic)
{
	if (this != &ic)
		type = ic.getType();
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Destructor Ice" << std::endl;
}

AMateria*	Ice::clone() const
{
	return (new Ice());
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
