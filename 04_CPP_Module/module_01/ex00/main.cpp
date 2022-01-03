/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:09:26 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 14:08:25 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 17:44:05 by hkwon            ###   ########.fr       */
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

<<<<<<< HEAD
std::string	randomName(void)
{
	std::string	name;

	name += (char)(rand() % 26 + 'A');
	name += (char)(rand() % 10 + '0');

	return (name);
}
=======
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400

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
<<<<<<< HEAD
	for (int i = 0; i < 10; i++)
		randomChump(randomName());
=======
	randomChump("RandomZombie");
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
	return (0);
}
