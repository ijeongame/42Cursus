/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 01:08:01 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/15 21:05:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(std::string _name);
		ScavTrap(const ScavTrap &s);
		virtual ~ScavTrap(void);
		ScavTrap	&operator=( ScavTrap const &s);

		void	attack(std::string const &target);
		void	guardGate(void);
};

#endif

