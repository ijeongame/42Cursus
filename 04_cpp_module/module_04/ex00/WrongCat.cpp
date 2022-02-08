/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:32:52 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 21:04:20 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "<WrongCat> Animal Constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& c) : WrongAnimal()
{
	type = c.getType();
	std::cout << "<WrongCat> Animal Copy Constructor" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "<WrongCat> Animal Destructor" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat& c)
{
	if (this != &c)
		type = c.getType();
	std::cout << "<WrongCat> Operator= Overload" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow!" << std::endl;
}

