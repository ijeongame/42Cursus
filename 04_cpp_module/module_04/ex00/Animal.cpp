/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:22:55 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 21:03:58 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	type = "Default";
	std::cout << "<Default> Animal Constructor" << std::endl;
}

Animal::Animal(const Animal &a)
{
	type = a.getType();
	std::cout << "<Default> Animal Copy Constructor" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "<Default> Animal Destructor" << std::endl;
}

Animal	&Animal::operator=(const Animal& a)
{
	if (this != &a)
		this->type = a.getType();
	std::cout << "<Default> Operator= Overload" << std::endl;
	return (*this);
}

std::string	const &Animal::getType(void) const
{
	return (type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Cannot hear Animal Sound" << std::endl;
}
