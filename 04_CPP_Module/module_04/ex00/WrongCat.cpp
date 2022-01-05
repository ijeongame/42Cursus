/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:17:57 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/10 23:00:57 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Wrong Cat")
{
}

WrongCat::WrongCat(const WrongCat& wc) : WrongAnimal(wc)
{
	*this = wc;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Wrong Cat Destructor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& wc)
{
	this->WrongAnimal::operator=(wc);
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow!" << std::endl;
}
