/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:08:37 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/22 17:25:57 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	name = "Default";
	for (int i = 0; i < 4; i++)
		inven[i] = NULL;
	std::cout << "Default Constructor Character" << std::endl;
}

Character::Character(std::string const &_name)
{
	name = _name;
	for (int i = 0; i < 4; i++)
		inven[i] = NULL;
	std::cout << "Named Constructor Character" << std::endl;
}

Character::Character(Character const &ch)
{
	const AMateria*		temp;

	name = ch.getName();
	for (int i = 0; i < 4; i++)
	{
		if (inven[i])
		{
			delete inven[i];
			inven[i] = NULL;
		}
		temp = ch.getAMateria(i);
		if (temp)
			inven[i] = temp->clone();
	}
	std::cout << "Copy Constructor Character" << std::endl;
}

Character &Character::operator=(Character const &ch)
{
	const AMateria*	temp;

	if (this != &ch)
	{
		name = ch.getName();
		for (int i = 0; i < 4; i++)
		{
			if (inven[i])
			{
				delete inven[i];
				inven[i] = NULL;
			}
			temp = ch.getAMateria(i);
			if (temp)
				inven[i] = temp->clone();
		}
	}
	std::cout << "Operator= Overload" << std::endl;
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (inven[i])
		{
			delete inven[i];
			inven[i] = NULL;
		}
	}
	std::cout << "Destructor Character" << std::endl;
}

std::string const &Character::getName() const
{
	return (name);
}

AMateria const *Character::getAMateria(int index) const
{
	return (inven[index]);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!inven[i])
		{
			inven[i] = m;
			std::cout << "i : " << i << " inven check : " << inven[i]->getType() << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inven[idx])
	{
		inven[idx] = NULL;
	}
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inven[idx])
		inven[idx]->use(target);
}
