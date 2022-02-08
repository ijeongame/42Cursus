/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:29:02 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/08 23:59:48 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	index = 0;
	old_index = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::AddContact()
{
	if (index == 8)
	{
		Contact temp_c;
		temp_c.ContactInput();
		c[old_index] = temp_c;
		old_index++;
		if (old_index == 8)
			old_index = 0;
	}
	else
	{
		Contact temp_c;
		temp_c.ContactInput();
		c[index] = temp_c;
		index++;
	}
}

void	PhoneBook::PrintContact()
{
	int i;

	std::cout << "Enter index to get full page : ";
	std::cin >> i;
	if (std::cin.eof())
		return ;
	if (std::cin.fail() || i < 1 || i >= index + 1)
	{
		std::cout << "Wrong Index" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		return PrintContact();
	}
	else
		c[i - 1].ContactShow();
}

void PhoneBook::PrintPhoneBook()
{
	int			i;

	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "index";
	std::cout << "|" << std::setw(10) << std::right << "firstName";
	std::cout << "|" << std::setw(10) << std::right << "lastName";
	std::cout << "|" << std::setw(10) << std::right << "nickName" << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (i = 0; i < index; i++)
	{
		c[i].showShortInfo(i);
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
}

void	PhoneBook::SearchContact()
{
	if (index == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	PrintPhoneBook();
	PrintContact();
	return ;
}


std::string makeUpper(std::string command)
{
	std::string res;
	int i = -1;

	while (command[++i])
		res.append(1, toupper(command[i]));
	return (res);
}
