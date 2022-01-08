/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:02:14 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/09 00:01:35 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

void	Contact::ContactInput()
{
	std::cout << "first name : ";
	std::cin >> first_name;
	std::cout << "last name : ";
	std::cin >> last_name;
	std::cout << "nickname : ";
	std::cin >> nickname;
	std::cout << "phone number : ";
	std::cin >> phone_number;
	std::cout << "darkest secret : ";
	std::cin >> darkest_secret;
}

void	Contact::ContactShow()
{
	std::cout << "first name : " << first_name << std::endl;
	std::cout << "last name : " << last_name << std::endl;
	std::cout << "nickname : " << nickname << std::endl;
	std::cout << "phone number : " << phone_number << std::endl;
	std::cout << "darkest secret : " << darkest_secret << std::endl;
}

void	Contact::setString(std::string info)
{
	if (info.length() > 10)
		std::cout << "|" << std::setw(10) << std::right << info.substr(0, 9) + ".";
	else
		std::cout << "|" << std::setw(10) << std::right << info;
}

void	Contact::showShortInfo(int i)
{
	std::cout << "|" << std::setw(10) << std::right << i + 1;
	setString(first_name);
	setString(last_name);
	setString(nickname);
	std::cout << "|" << std::endl;
}


