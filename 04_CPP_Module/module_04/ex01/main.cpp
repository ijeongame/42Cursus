/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:32:47 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/15 02:17:56 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	srand((unsigned int)time(NULL));
	Animal *Animals[10];
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}
	for (int i = 0; i < 10; ++i)
		delete Animals[i];

	std::cout << std::endl;
	std::cout << "🌈deep check🌈" << std::endl;
	Dog test1;
	Dog test2;
	std::cout << "test1 Brain : " << test1.getBrain() << std::endl;
	std::cout << "test2 Brain : " << test2.getBrain() << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << "test1 Brain Idea : " << test1.getBrain()->getIdea(i) << " = ";
		std::cout << "test2 Brain Idea : " << test2.getBrain()->getIdea(i) << std::endl;
	}
	test1 = test2;
	std::cout << test1.getBrain() << std::endl;
	std::cout << test2.getBrain() << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << test1.getBrain()->getIdea(i) << " = ";
		std::cout << test2.getBrain()->getIdea(i) << std::endl;
	}
	std::cout << "deep check fin" << std::endl;

	std::cout << "🌈deep check🌈" << std::endl;
	Dog basic;
	Dog tmp = basic;

	std::cout << std:: endl;
	std::cout << basic.getBrain() << std::endl;
	std::cout << tmp.getBrain() << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << test1.getBrain()->getIdea(i) << " = ";
		std::cout << test2.getBrain()->getIdea(i) << std::endl;
	}
	return (0);
}
