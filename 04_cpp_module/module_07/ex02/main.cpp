/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 22:56:41 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/28 21:26:50 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 10

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	// numbers = Array<int> counts(10);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() % 10;
		numbers[i] = value;
		mirror[i] = value;
	}
	//PRINT
	std::cout << "======================" << std::endl;
	std::cout << "numbers print" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << numbers[i] << ' ';
	std::cout << std::endl;
	std::cout << "======================" << std::endl;
	std::cout << "mirror print" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << mirror[i] << ' ';
	std::cout << std::endl;
	//SCOPE
	{
		Array<int> tmp1, tmp2;
		tmp1 = numbers;
		tmp2 = numbers;
		std::cout << "======================" << std::endl;
		std::cout << "tmp print" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
			std::cout << tmp1[i] << ' ';
		std::cout << std::endl;
		Array<int> test(tmp1);
		std::cout << "======================" << std::endl;
		std::cout << "test print" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
			std::cout << test[i] << ' ';
		std::cout << std::endl;
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

// #define MAX_VAL 30

// template <class T>
// void printArr(Array<T>& numbers) {
//     for (int i = 0; i < MAX_VAL; i++) {
//         std::cout << numbers[i] << ' ';
//     }
//     std::cout << std::endl;
// }

// template <class P>
// void printPtrarr(P* array) {
//     for (int i = 0; i < MAX_VAL; i++) {
//         std::cout << array[i] << ' ';
//     }
//     std::cout << std::endl;
// }
