/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 01:44:14 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/10 22:51:31 by hkwon            ###   ########.fr       */
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
		WrongAnimal(std::string _type);
		WrongAnimal(const WrongAnimal &wa);
		virtual ~WrongAnimal(void);
		WrongAnimal&	operator=(const WrongAnimal& wa);

		std::string const &getType(void) const;

		void makeSound(void) const;
};

#endif
