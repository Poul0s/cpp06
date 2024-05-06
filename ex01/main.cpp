/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:30:54 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 15:47:44 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	uintptr_t	serialized;
	int			res = 0;

	data.data = 42;
	std::cout << "Data address: \t\t" << &data << std::endl;
	serialized = Serializer::serialize(&data);
	if (serialized != reinterpret_cast<uintptr_t>(&data))
		res++;
	std::cout << "Serialized address: \t0x" << std::setbase(16) << serialized << std::setbase(10) <<  std::endl;
	if (Serializer::deserialize(serialized) != &data)
		res++;
	std::cout << "Deserialized address: \t" << Serializer::deserialize(serialized) << std::endl;
	data = *Serializer::deserialize(serialized);
	if (data.data != 42)
		res++;
	std::cout << "Data content: " << data.data << std::endl;

	return (res);
}
