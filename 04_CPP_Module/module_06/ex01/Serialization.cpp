/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkwon <hkwon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:35:06 by hkwon             #+#    #+#             */
/*   Updated: 2022/01/05 18:11:05 by hkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t serialize(Data* ptr)
{
	// value in struct cast
	// 1byte
	char *raw = new char[sizeof(int) + sizeof(int) + ptr->name.size() + sizeof(double)];
	*(reinterpret_cast<int *>(raw)) = ptr->age;
	*(reinterpret_cast<int *>(raw + sizeof(int))) = *(ptr->phone);
	*(reinterpret_cast<std::string *>(raw + sizeof(int) + sizeof(int))) = ptr->name;
	*(reinterpret_cast<double *>(raw + sizeof(int) + sizeof(int) + ptr->name.size() + 1)) = ptr->score;

	return (reinterpret_cast<uintptr_t>(raw));

	// struct class address cast
	// network problem
	// return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	Data *deserial = new Data;
	deserial->phone = new int;
	char *ptr = reinterpret_cast<char *>(raw);

	deserial->age = *reinterpret_cast<int *>(ptr);
	*(deserial->phone) = *reinterpret_cast<int *>(ptr + sizeof(int));
	deserial->name = *reinterpret_cast<std::string *>(ptr + sizeof(int) + sizeof(int));
	deserial->score = *reinterpret_cast<double *>(ptr + sizeof(int) + sizeof(int) + deserial->name.size() + 1);

	return (deserial);
	// return (reinterpret_cast<Data*>(raw));
}
