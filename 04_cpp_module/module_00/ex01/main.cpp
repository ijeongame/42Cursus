/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:41:38 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/09 00:02:10 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string command;
	PhoneBook pb;

	while (1)
	{
		std::cout << "Enter Command(ADD/SEARCH/EXIT) : ";
		std::cin >> command;
		command = makeUpper(command);
		if (command == "ADD")
			pb.AddContact();
		else if (command == "SEARCH")
			pb.SearchContact();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Sorry : Wrong Command" << std::endl;
	}
	return (0);
}
