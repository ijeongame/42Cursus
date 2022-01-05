/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 01:08:06 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/02 23:42:33 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap <"<< name << "> Constructor" << std::endl;
	setHitPoints(100);
	setEnergyPoint(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "ScavTrap <" << name << "> Constructor" << std::endl;
	setName(_name);
	setHitPoints(100);
	setEnergyPoint(50);
	setAttackDamage(20);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap <" << name << "> Destructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s) : ClapTrap(s)
{
	std::cout << "ScavTrap Copy Constructor" << std::endl;
	*this = s;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s)
{
	this->ClapTrap::operator=(s);
	// if (this != &s)
	// {
	// 	name = s.getName();
	// 	hitPoints = s.getHitPoints();
	// 	energyPoint = s.getEnergyPoint();
	// 	attackDamage = s.getAttackDamage();
	// }
	std::cout << "ScavTrap Operator = <" << name << "> Overload" << std::endl;
	return (*this);
}

void ScavTrap::attack(std::string const & target)
{
	std::cout << "ScavTrap <" << name << "> attacks <" << target
		<< ">, causing <" << attackDamage << "> points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap <" << name << "> have enterred in Gate keeper mode." << std::endl;
}
