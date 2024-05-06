/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:03:14 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 15:03:31 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(Serializer const &copy)
{
	(void)copy;
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}