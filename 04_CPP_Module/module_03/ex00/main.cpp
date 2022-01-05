/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:21:59 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/01 22:40:24 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Inheritance
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("a");
	ClapTrap	b("b");
	ClapTrap	c("c");

	std::cout << std::endl;

	a.attack("b");
	b.takeDamage(a.getAttackDamage());

	std::cout << std::endl;

	b.attack("a");
	a.takeDamage(b.getAttackDamage());

	std::cout << std::endl;

	c.attack("b");
	b.takeDamage(c.getAttackDamage());

	std::cout << std::endl;

	a.beRepaired(25);

	std::cout << std::endl;
	return (0);
}
