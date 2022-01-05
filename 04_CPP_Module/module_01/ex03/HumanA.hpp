/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 22:42:55 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/04 22:50:01 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	private:
		Weapon		&weapon;
		std::string name;
	public:
		HumanA(std::string name, Weapon &weapon);
		void attack();
		~HumanA();
};

#endif
