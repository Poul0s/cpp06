/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:32:08 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 15:32:32 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
}

Data::Data(const Data &copy)
{
	*this = copy;
}

Data::~Data()
{
}

Data &Data::operator=(const Data &copy)
{
	this->data = copy.data;
	return *this;
}
