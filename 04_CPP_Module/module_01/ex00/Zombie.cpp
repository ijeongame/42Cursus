/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:22:10 by hkwon             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/24 16:50:28 by hkwon            ###   ########.fr       */
=======
/*   Updated: 2021/12/28 00:55:01 by hkwon            ###   ########.fr       */
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (){
}

Zombie::Zombie (std::string name){
	this->name = name;
}

Zombie::~Zombie() {
<<<<<<< HEAD
	std::cout << name << "is dead..." << std::endl;
}

void Zombie::announce(){
	std::cout << '<' << name << '>' << " BraiiiiiiinnnzzzZ..." << std::endl;
=======
	std::cout << '<' << this->name << '>' << " is dead..." << std::endl;
}

void Zombie::announce(){
	std::cout << '<' << this->name << '>' << " BraiiiiiiinnnzzzZ..." << std::endl;
>>>>>>> 64486e2be31f95f0ddcc8b6a18b59d1662c43400
}
