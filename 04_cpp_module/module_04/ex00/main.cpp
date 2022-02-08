/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 02:32:47 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/21 17:50:59 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
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
