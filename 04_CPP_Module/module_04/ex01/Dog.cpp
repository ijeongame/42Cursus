/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:43:13 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 21:12:58 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "<Dog> Animal Constructor" << std::endl;
}

Dog::Dog(const Dog& c) : Animal()
{
	type = c.getType();
	brain = new Brain(*c.getBrain());
	std::cout << "<Dog> Animal Copy Constructor" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "<Dog> Animal Destructor" << std::endl;
	delete brain;
}

Dog	&Dog::operator=(const Dog& c)
{
	if (this != &c)
	{
		type = c.getType();
		*brain = *c.getBrain();
	}
	std::cout << "<Dog> Operator= Overload" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bowwow Bowwow!" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	if (brain)
		return (brain);
	return (NULL);
}
