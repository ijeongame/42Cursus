/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:24:23 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/05 17:58:41 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main(void)
{
	Data hkwon;

	hkwon.age = 29;
	hkwon.phone = new int(9778);
	hkwon.name = "hkwon";
	hkwon.score = 42.5;

	uintptr_t out = serialize(&hkwon);

	Data* data = deserialize(out);
	std::cout << "age : " << data->age << std::endl;
	std::cout << "phone : " << *data->phone << std::endl;
	std::cout << "score : " << data->score << std::endl;
	std::cout << "name : " << data->name << std::endl;
}
