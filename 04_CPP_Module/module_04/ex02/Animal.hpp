/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:52:44 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/18 21:35:18 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const Animal &a);
		virtual ~Animal(void);
		Animal&	operator=(const Animal& a);

		std::string const &getType(void) const;

		virtual void makeSound(void) const = 0;
};

#endif

