/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:01:17 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/10 23:01:02 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "Wrong Default";
	std::cout << this->type << " Animal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(std::string _type)
{
	this->type = _type;
	std::cout << this->type << " Animal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	*this = wa;
	std::cout << wa.type << " Wrong Animal Copy Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Wrong Animal Destructor" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& wa)
{
	if (this != &wa)
		this->type = wa.getType();
	return (*this);
}

std::string	const &WrongAnimal::getType(void) const
{
	return (type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Cannot hear Wrong Animal Sound" << std::endl;
}
