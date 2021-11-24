/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:53:41 by hkwon             #+#    #+#             */
/*   Updated: 2021/11/24 17:43:32 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// 생성과 동시에 초기화를 시켜준다. 객체를 생성하기전에 초기화를 하는 부분.
HumanA::HumanA (std::string name, Weapon &weapon) : weapon(weapon){
	// 객체가 생성된 후에 변경
	this->name = name;
}

void HumanA::attack(){
	std::cout << name << "attacks with is" << weapon.getType() << std::endl;
}

HumanA::~HumanA (){
}
