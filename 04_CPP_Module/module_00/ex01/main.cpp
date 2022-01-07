/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:41:38 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/07 21:26:41 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string command;
	PhoneBook pb[8];
	int i = 0;

	std::cout << "Welecome My Awesome Phonebook" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "Enter Command(ADD/SEARCH/EXIT) : " << std::endl;
		std::getline(std::cin, command);
		command = makeUpper(command);
		if (command == "ADD")
			pb[i++ % 8].ContactAdd();
		else if (command == "SEARCH")
		{
			if (i > 8)
				pb[i].SearchInfo(pb, 8);
			else
				pb[i].SearchInfo(pb, i);
		}
		else if (command == "EXIT")
		{
			std::cout << "Thank You : Good Bye" << std::endl;
			break ;
		}
		else
			std::cout << "Sorry : Wrong Command" << std::endl;
	}
	return (0);
}
