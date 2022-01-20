/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:01:17 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 21:04:16 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	type = "Wrong Default";
	std::cout << "<WrongDefault> Animal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wa)
{
	type = wa.getType();
	std::cout << "<WrongDefault> Animal Copy Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "<WrongDefault> Animal Destructor" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& wa)
{
	if (this != &wa)
		type = wa.getType();
	std::cout << "<WrongDefault> Operator= Overload" << std::endl;
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
