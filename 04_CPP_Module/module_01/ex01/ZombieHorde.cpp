/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:09:57 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 15:37:24 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 19:17:39 by hkwon            ###   ########.fr       */
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *newZombie = new Zombie[N];
	for (int i = 0; i < N; i++)
<<<<<<< HEAD
	{
		newZombie[i].getName();
		newZombie[i].setName(name);
	}
	for (int i = 0; i < N; i++)
		newZombie[i].announce();
=======
		newZombie[i].setName(name);
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
	return (newZombie);
}
