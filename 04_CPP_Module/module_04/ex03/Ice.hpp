/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:32:23 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/18 02:30:28 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(std::string const type);
		Ice(Ice const &ic);
		Ice	&operator=(Ice const &ic);
		~Ice(void);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
