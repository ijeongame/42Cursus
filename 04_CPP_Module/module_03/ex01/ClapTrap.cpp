/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:24:29 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 20:55:16 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Defalut")
{
	std::cout << "ClapTrap <" << name << "> Constructor" << std::endl;
	hitPoints = 10;
	energyPoint = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string _name) : name(_name)
{
	std::cout << "ClapTrap <" << _name << "> Constructor" << std::endl;
	hitPoints = 10;
	energyPoint = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
	std::cout << "ClapTrap Copy Constructor" << std::endl;
	*this = c;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap <" << name << "> Distructor" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& c)
{
	if (this != &c)
	{
		name = c.getName();
		hitPoints = c.getHitPoints();
		energyPoint = c.getEnergyPoint();
		attackDamage = c.getAttackDamage();
	}
	std::cout << "ClapTrap Operator = <" << name << "> Overload" << std::endl;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap <" << name << "> attacks <" << target
		<< ">, causing <" << attackDamage << "> points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints < amount)
		hitPoints = 0;
	std::cout << "ClapTrap <" << name << "> took " << amount << " damage!" << std::endl;
	hitPoints -= amount;
	std::cout << "ClapTrap <" << name << "> remained " << hitPoints << " hitPoint" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap <" << name << "> " << amount << " Repaired!" << std::endl;
	hitPoints += amount;
	std::cout << "ClapTrap <" << name << "> remained " << hitPoints << " Point" << std::endl;
}

std::string		ClapTrap::getName(void) const
{
	return (name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (hitPoints);
}

unsigned int	ClapTrap::getEnergyPoint(void) const
{
	return (energyPoint);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (attackDamage);
}

void	ClapTrap::setName(std::string _name)
{
	name = _name;
}

void	ClapTrap::setHitPoints(unsigned int _hitPoints)
{
	hitPoints = _hitPoints;
}

void	ClapTrap::setEnergyPoint(unsigned int _energyPoint)
{
	energyPoint = _energyPoint;
}

void	ClapTrap::setAttackDamage(unsigned int _attackDamage)
{
	attackDamage = _attackDamage;
}
