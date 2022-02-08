/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:11:17 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/05 23:03:11 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap <"<< name << "> Constructor" << std::endl;
	setHitPoints(100);
	setEnergyPoint(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
	std::cout << "FragTrap <" << name << "> constructor." << std::endl;
	setName(name);
	setHitPoints(100);
	setEnergyPoint(100);
	setAttackDamage(30);
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap <" << name << "> destructor." << std::endl;
}

FragTrap::FragTrap(const FragTrap& f) : ClapTrap(f)
{
	std::cout << "FragTrap copy constructor." << std::endl;
	*this = f;
}

FragTrap& FragTrap::operator=(const FragTrap& f)
{
	if (this != &f)
	{
		name = f.getName();
		hitPoints = f.getHitPoints();
		energyPoint = f.getEnergyPoint();
		attackDamage = f.getAttackDamage();
	}
	std::cout << "FragTrap Operator = <" << name << "> Overload" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap <" << name << "> Positive high Fives Guys" << std::endl;
}
