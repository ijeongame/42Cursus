/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:03:08 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/10 23:00:43 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
}

Cat::Cat(const Cat& c) : Animal(c)
{
	*this = c;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor" << std::endl;
}

Cat	&Cat::operator=(const Cat& c)
{
	this->Animal::operator=(c);
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow!" << std::endl;
}
