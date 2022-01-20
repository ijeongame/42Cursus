/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:43:13 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 21:04:04 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
	std::cout << "<Dog> Animal Constructor" << std::endl;
}

Dog::Dog(const Dog& c) : Animal()
{
	type = c.getType();
	std::cout << "<Dog> Animal Copy Constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "<Dog> Animal Destructor" << std::endl;
}

Dog	&Dog::operator=(const Dog& c)
{
	if (this != &c)
		type = c.getType();
	std::cout << "<Dog> Operator= Overload" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow Bowwow!" << std::endl;
}
