/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:43:13 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/10 23:49:28 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	this->brain = new Brain();
}

Dog::Dog(const Dog& d) : Animal(d)
{
	*this = d;
	this->brain = new Brain(*d.getBrain());
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor" << std::endl;
	delete this->brain;
}

Dog	&Dog::operator=(const Dog& d)
{
	if (this != &d)
	{
		this->Animal::operator=(d);
		this->brain = new Brain(*d.getBrain());
	}
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
