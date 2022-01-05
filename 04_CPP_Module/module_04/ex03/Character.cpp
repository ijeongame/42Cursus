/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:08:37 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/20 00:00:54 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	this->name = "Default";
	for (int i = 0; i < 4; i++)
		this->inven[i] = NULL;
	std::cout << this->name << " Constructor Character" << std::endl;
}

Character::Character(std::string const &_name)
{
	this->name = _name;
	for (int i = 0; i < 4; i++)
		this->inven[i] = NULL;
	std::cout << this->name << " Constructor Character" << std::endl;
}

Character::Character(Character const &ch)
{
	const AMateria*		temp;

	this->name = ch.getName();
	for (int i = 0; i < 4; i++)
	{
		if (this->inven[i])
		{
			delete this->inven[i];
			this->inven[i] = NULL;
		}
		temp = ch.getAMateria(i);
		if (temp)
			this->inven[i] = temp->clone();
	}
	std::cout << "Copy Constructor Character" << std::endl;
}

Character &Character::operator=(Character const &ch)
{
	const AMateria*		temp;

	if (this != &ch)
	{
		this->name = ch.getName();
		for (int i = 0; i < 4; i++)
		{
			if (inven[i])
			{
				delete inven[i];
				inven[i] = NULL;
			}
			temp = ch.getAMateria(i);
			if (temp)
				this->inven[i] = temp->clone();
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inven[i])
		{
			delete this->inven[i];
			this->inven[i] = NULL;
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
	return (this->inven[index]);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!this->inven[i])
		{
			this->inven[i] = m;
			std::cout << "equip Character : " << name << std::endl;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->inven[idx])
		this->inven[idx] = NULL;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inven[idx])
		this->inven[idx]->use(target);
}
