/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:11:00 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/28 19:26:11 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
	private :
		std::string	name;
	public :
		Zombie();
		Zombie(std::string name);
		void announce();
		~Zombie();

		void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
