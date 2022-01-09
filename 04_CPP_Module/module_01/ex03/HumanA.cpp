/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:53:41 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/09 22:21:40 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon &weapon) : weapon(weapon){
	this->name = name;
}

void HumanA::attack(){
	std::cout << name << " attacks with is " << weapon.getType() << std::endl;
}

HumanA::~HumanA (){
}
