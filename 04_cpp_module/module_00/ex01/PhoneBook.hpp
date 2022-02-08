/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:47:42 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/08 23:32:19 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook {
	private:
		Contact c[8];
		int		index;
		int		old_index;
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	AddContact();
		void	SearchContact();
		void	PrintPhoneBook();
		void	PrintContact();
};

std::string makeUpper(std::string command);

#endif
