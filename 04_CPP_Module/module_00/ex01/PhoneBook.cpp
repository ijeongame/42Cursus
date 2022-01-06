/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 23:29:02 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/06 17:29:54 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

//1 ContactAdd()
void	PhoneBook::ContactAdd()
{
	std::cout << "first name : ";
	std::getline(std::cin, first_name);
	if (std::cin.eof())
		return ;
	std::cout << "last name : ";
	std::getline(std::cin, last_name);
	if (std::cin.eof())
		return ;
	std::cout << "nickname : ";
	std::getline(std::cin, nickname);
	if (std::cin.eof())
		return ;
	std::cout << "phone number : ";
	std::getline(std::cin, phone_number);
	if (std::cin.eof())
		return ;
	std::cout << "darkest secret : ";
	std::getline(std::cin, darkest_secret);
	if (std::cin.eof())
		return ;
}

void	PhoneBook::ContactSearch()
{
	std::cout << "firstName : " + first_name << std::endl;
	std::cout << "lastName : " + last_name << std::endl;
	std::cout << "nickName : " + nickname << std::endl;
	std::cout << "phoneNumber : " + phone_number << std::endl;
}

void	PhoneBook::setString(std::string info)
{
	if (info.length() > 10)
		std::cout << "|" << std::setw(10) << std::right << info.substr(0, 9) + ".";
	else
		std::cout << "|" << std::setw(10) << std::right << info;
}

void	PhoneBook::showShortInfo(int i)
{
	std::cout << "|" << std::setw(10) << std::right << i + 1;
	setString(first_name);
	setString(last_name);
	setString(nickname);
	std::cout << "|" << std::endl;
}

int	PhoneBook::getIndex(int size)
{
	int	i;

	std::cout << "Enter index to get full page : ";
	std::cin >> i;
	if (std::cin.eof())
		return (-1);
	if (std::cin.fail() || i < 1 || i >= size + 1)
	{
		std::cout << "Wrong Index" << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		return getIndex(size);
	}
	else
		return (i);
}

void PhoneBook::SearchInfo(PhoneBook pb[8], int size)
{
	int			i;

	std::cout << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|" << std::setw(10) << std::right << "index";
	std::cout << "|" << std::setw(10) << std::right << "firstName";
	std::cout << "|" << std::setw(10) << std::right << "lastName";
	std::cout << "|" << std::setw(10) << std::right << "nickName" << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (i = 0; i < size; i++)
	{
		pb[i].showShortInfo(i);
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	if (size > 0)
	{
		i = getIndex(size);
		pb[i - 1].ContactSearch();
		std::cin.ignore();
	}
}
