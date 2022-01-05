/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 01:37:20 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/05 00:36:50 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &d);
		DiamondTrap(std::string _name);
		~DiamondTrap(void);
		DiamondTrap	&operator=(const DiamondTrap &d);

		std::string	const getName(void) const;
		void	attack(std::string const &target);
		void	whoAmI(void);
};

#endif
