/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:21:59 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/02 23:10:37 by hkwon            ###   ########.fr       */
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
	return (0);
}
