/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:47:45 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/05 00:45:54 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : name(ClapTrap::name){
	ClapTrap::name += "_clap_name";
	std::cout << "DiamondTrap Default Constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name + "_clap_name"){
	name = _name;
	std::cout << "DiamondTrap <" << name << "> constructor." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap <" << name << "> destructor." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d) : ClapTrap(d)
{
	std::cout << "DiamondTrap copy constructor." << std::endl;
	*this = d;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d) {
	ClapTrap::operator=(d);
	// name = d.name;
	std::cout << "DiamondTrap " << "assignation overloading." << std::endl;
	return (*this);
}

std::string	const	DiamondTrap::getName(void) const
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
