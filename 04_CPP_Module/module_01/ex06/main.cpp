/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:16:49 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/04 22:46:21 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char *argv[])
{
	Karen	karen;

	if (argc != 2)
		std::cout << "check input ./karenFilter [ level ]" << std::endl;
	else
		karen.complain(argv[1]);
	return (0);
}
