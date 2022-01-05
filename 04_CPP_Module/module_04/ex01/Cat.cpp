/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:03:08 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/10 23:34:53 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	this->brain	= new Brain();
}

Cat::Cat(const Cat& c) : Animal(c)
{
	*this = c;
	this->brain = new Brain(*c.getBrain());
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor" << std::endl;
	delete	this->brain;
}

Cat	&Cat::operator=(const Cat& c)
{
	if (this != &c)
	{
		this->Animal::operator=(c);
		this->brain = new Brain(*c.getBrain());
	}
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
