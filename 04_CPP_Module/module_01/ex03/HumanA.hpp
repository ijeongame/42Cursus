/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:23:43 by hkwon             #+#    #+#             */
/*   Updated: 2021/11/24 17:43:34 by hkwon            ###   ########.fr       */
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
