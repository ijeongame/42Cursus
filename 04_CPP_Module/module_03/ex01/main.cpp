/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:21:59 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/15 19:44:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Inheritance
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	a("a");
	ScavTrap	b("b");

	std::cout << std::endl;

	a.attack("b");
	b.takeDamage(a.getAttackDamage());

	std::cout << std::endl;

	b.attack("a");
	a.takeDamage(b.getAttackDamage());

	std::cout << std::endl;

	a.attack("b");
	b.takeDamage(a.getAttackDamage());

	std::cout << std::endl;

	b.attack("a");
	a.takeDamage(b.getAttackDamage());

	std::cout << std::endl;

	b.guardGate();

	std::cout << std::endl;

	std::cout << "====" << std::endl;
	//upcasting - overriding
	// ScavTrap d;
	// ClapTrap *e = &d;

	// d.attack("a");
	// e->attack("a");

	ClapTrap	*c = new ScavTrap("c");

	c->attack("a");
	delete c;

	return (0);
}
