/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:19:53 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/19 20:48:32 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(std::string const _type);
		Cure(Cure const &cu);
		Cure	&operator=(Cure const &cu);
		virtual ~Cure(void);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif
