/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:47:42 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/07 21:26:46 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>

class PhoneBook {
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		PhoneBook();
		~PhoneBook();

		void	ContactAdd();
		void	ContactSearch();
		int		getIndex(int size);
		void	setString(std::string info);
		void	showShortInfo(int);
		void	SearchInfo(PhoneBook pb[8], int size);
};

std::string makeUpper(std::string command);

#endif
