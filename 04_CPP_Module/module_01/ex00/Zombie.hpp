/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:18:50 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/04 22:47:24 by hkwon            ###   ########.fr       */
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
		~Zombie();

		void announce(void);
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

#endif
