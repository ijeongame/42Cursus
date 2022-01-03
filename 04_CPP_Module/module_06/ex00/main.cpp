/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:03:42 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/03 17:48:43 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error : Cannot Convert! Check Argument [./convert arg]" << std::endl;
		return (1);
	}
	Convert c(argv[1]);
	std::cout << c;
	return (0);
}
