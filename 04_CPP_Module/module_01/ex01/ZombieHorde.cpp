/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:09:57 by hkwon             #+#    #+#             */
/*   Updated: 2021/11/24 15:37:24 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *newZombie = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		newZombie[i].getName();
		newZombie[i].setName(name);
	}
	for (int i = 0; i < N; i++)
		newZombie[i].announce();
	return (newZombie);
}
