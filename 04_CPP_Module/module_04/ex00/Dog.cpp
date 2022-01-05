/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:43:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/10 23:37:35 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
}

Dog::Dog(const Dog& d) : Animal(d)
{
	*this = d;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor" << std::endl;
}

Dog	&Dog::operator=(const Dog& d)
{
	this->Animal::operator=(d);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow Bowwow!" << std::endl;
}
