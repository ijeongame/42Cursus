/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:44:14 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 20:31:16 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &wa);
		virtual ~WrongAnimal(void);
		WrongAnimal&	operator=(const WrongAnimal& wa);

		std::string const &getType(void) const;

		void makeSound(void) const;
};

#endif
