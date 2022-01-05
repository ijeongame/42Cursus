/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:32:47 by hkwon             #+#    #+#             */
/*   Updated: 2021/12/10 23:02:13 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();

	// std::cout << std::endl;
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound();
	// j->makeSound();
	// meta->makeSound();

	// std::cout << std::endl;
	// delete meta;
	// delete j;
	// delete i;

	// std::cout << std::endl;
	// const WrongAnimal* testAnimal = new WrongAnimal();
	// const WrongAnimal* testCat = new WrongCat();
	// std::cout << std::endl;
	// testAnimal->makeSound();
	// testCat->makeSound();
	// std::cout << std::endl;

	// delete testAnimal;
	// delete testCat;

		const Animal *meta = new Animal();
		const Animal *dog = new Dog();
		const Animal *cat = new Cat();
		const WrongAnimal *wrong = new WrongCat();
		std::cout << "type : " << dog->getType() << std::endl;
		std::cout << "type : " << cat->getType() << std::endl;
		cat->makeSound();
		dog->makeSound();
		meta->makeSound();
		wrong->makeSound();
		delete meta;
		delete cat;
		delete dog;
		delete wrong;

	return (0);
}
