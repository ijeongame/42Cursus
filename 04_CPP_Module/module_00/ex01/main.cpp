/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:41:38 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/20 20:02:21 by hkwon            ###   ########.fr       */
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
		std::transform(command.begin(), command.end(), command.begin(), toupper);
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
