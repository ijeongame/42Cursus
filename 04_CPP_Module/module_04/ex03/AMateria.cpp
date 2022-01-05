/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 02:32:39 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/19 23:36:02 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	this->type = "Default";
	std::cout << "Default Constructor AMateria" << std::endl;
}

AMateria::AMateria(std::string const & _type)
{
	this->type = _type;
	std::cout << "Named Constructor AMateria" << std::endl;
}

AMateria::AMateria(AMateria const &am)
{
	this->type = am.getType();
	std::cout << this->type << " Copy Constructor AMateria" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &am)
{
	if (this != &am)
		this->type = am.getType();
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "Destructor AMateria" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (type);
} //Returns the materia type

void AMateria::use(ICharacter& target)
{
	std::cout << "Use function AMateria " << target.getName() << std::endl;
}
