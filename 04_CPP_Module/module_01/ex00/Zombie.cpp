/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:22:10 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/28 00:55:01 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (){
}

Zombie::Zombie (std::string name){
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << '<' << this->name << '>' << " is dead..." << std::endl;
}

void Zombie::announce(){
	std::cout << '<' << this->name << '>' << " BraiiiiiiinnnzzzZ..." << std::endl;
}
