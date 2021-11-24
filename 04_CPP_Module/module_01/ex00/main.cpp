/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:09:26 by hkwon             #+#    #+#             */
/*   Updated: 2021/11/24 14:08:25 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string	randomName(void)
{
	std::string	name;

	name += (char)(rand() % 26 + 'A');
	name += (char)(rand() % 10 + '0');

	return (name);
}

int	main(void)
{
	Zombie	stackZombie = Zombie("stackZombie");
	stackZombie.announce();

	// heapZombie use heap memory
	// heap memory is allocated using new() operator
	// heap memory must free before program exit
	Zombie *heapZombie = newZombie("heapZombie");
	heapZombie->announce();
	delete	heapZombie;

	// randomChump use stack memory
	for (int i = 0; i < 10; i++)
		randomChump(randomName());
	return (0);
}
