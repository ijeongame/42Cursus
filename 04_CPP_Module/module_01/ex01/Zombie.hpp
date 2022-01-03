/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:11:00 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 15:35:22 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 19:26:11 by hkwon            ###   ########.fr       */
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
		void announce();
		~Zombie();
<<<<<<< HEAD
	const std::string getName(){
		return (name);
	}
	void setName(std::string name){
		this->name = name;
	}
=======

		void setName(std::string name);
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
};

Zombie *zombieHorde(int N, std::string name);

#endif
