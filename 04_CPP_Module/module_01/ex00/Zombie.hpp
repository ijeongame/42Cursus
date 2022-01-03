/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:18:50 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 15:17:15 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 17:43:55 by hkwon            ###   ########.fr       */
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
<<<<<<< HEAD
=======
#include <string>
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400

class Zombie{
	private :
		std::string	name;
	public :
		Zombie();
		Zombie(std::string name);
<<<<<<< HEAD
		void announce();
		~Zombie();
=======
		~Zombie();

		void announce(void);
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif
