/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:32:47 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/21 18:41:08 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	{
		Animal *Animals[10];
		for (int i = 0; i < 10; ++i)
		{
			if (i % 2 == 0)
				Animals[i] = new Dog();
			else
				Animals[i] = new Cat();
		}
		std::cout << std::endl;
		std::cout << "DEEP COPY!!" << std::endl;
		std::cout << "-----------------------------" << std::endl;
		Dog copy(*(Dog *)Animals[4]);
		for (int i = 0; i < 100; ++i)
		{
			std::cout << copy.getBrain()->getIdea(i) << "    ";
			std::cout << ((Dog *)Animals[4])->getBrain()->getIdea(i) << std::endl;
		}
		std::cout << "-----------------------------"
				  << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			delete Animals[i];
		}
	}
	system("leaks brain");
}
