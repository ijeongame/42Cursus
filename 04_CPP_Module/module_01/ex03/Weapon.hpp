/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:16:44 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/09 23:02:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
	private:
		std::string	type;
		Weapon(void);
	public:
		Weapon(std::string type);
		const	std::string &getType(void);
		void	setType(std::string type);
		~Weapon();
};

#endif
