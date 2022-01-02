/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:09:26 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/28 17:44:05 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


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
	randomChump("RandomZombie");
	return (0);
}
