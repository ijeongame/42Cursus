/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:22:55 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/15 02:35:21 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Default";
	std::cout << this->type << " Animal Constructor" << std::endl;
}

Animal::Animal(std::string _type)
{
	this->type = _type;
	std::cout << this->type << " Animal Constructor" << std::endl;
}

Animal::Animal(const Animal &a)
{
	this->operator=(a);
	std::cout << a.type << " Animal Copy Constructor" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal	&Animal::operator=(const Animal& a)
{
	if (this != &a)
		this->type = a.getType();
	return (*this);
}

std::string	const &Animal::getType(void) const
{
	return (type);
}

// abstract class
// void	Animal::makeSound(void) const
// {
// 	std::cout << "Cannot hear Animal Sound" << std::endl;
// }
