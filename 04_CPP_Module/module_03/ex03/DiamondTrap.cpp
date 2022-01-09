/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:47:45 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/06 23:25:47 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

std::string		DiamondTrap::getName(void) const
{
	return (name);
}

void	DiamondTrap::attack(std::string const &target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void){
	std::cout << " Diamond Name : I'm " << name << std::endl;
	std::cout << "ClapTrap Name : I'm " << ClapTrap::name << std::endl;
}

DiamondTrap::DiamondTrap(void) : name(ClapTrap::name)
{
	ClapTrap::name += "_clap_name";
	std::cout << "DiamondTrap <"<< name <<"> Constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name")
{
	name = _name;
	FragTrap::setHitPoints(100);
	ScavTrap::setEnergyPoint(50);
	FragTrap::setAttackDamage(30);
	std::cout << "DiamondTrap <" << name << "> constructor." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap <" << name << "> destructor." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d)
{
	std::cout << "DiamondTrap copy constructor." << std::endl;
	*this = d;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d)
{
	// ClapTrap::operator=(d);
	if (this != &d)
	{
		name = d.getName();
		hitPoints = d.getHitPoints();
		energyPoint = d.getEnergyPoint();
		attackDamage = d.getAttackDamage();
	}
	std::cout << "DiamondTrap <" << name << "> assignation overloading." << std::endl;
	return (*this);
}
