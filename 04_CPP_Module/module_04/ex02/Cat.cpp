/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:03:08 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 21:10:32 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "<Cat> Animal Constructor" << std::endl;
}

Cat::Cat(const Cat& c) : Animal()
{
	type = c.getType();
	brain = new Brain(*c.getBrain());
	std::cout << "<Cat> Animal Copy Constructor" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "<Cat> Animal Destructor" << std::endl;
	delete brain;
}

Cat	&Cat::operator=(const Cat& c)
{
	if (this != &c)
	{
		type = c.getType();
		*brain = *c.getBrain();
	}
	std::cout << "<Cat> Operator= Overload" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow!" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	if (brain)
		return (brain);
	return (NULL);
}
