/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:56:39 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/27 18:55:25 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	srand(time(NULL));
	for (int i = 0 ; i < 10 ; ++i)
	{
		Base*	base = generate();
		identify(base);
		identify(*base);
		std::cout << std::endl;
		delete base;
	}
	return (0);
}
