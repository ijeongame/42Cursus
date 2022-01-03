/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:22:06 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 15:09:03 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 17:43:59 by hkwon            ###   ########.fr       */
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zombie = Zombie(name);
	zombie.announce();
}
