/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:00:28 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 16:20:31 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"
#include <iostream>

// identify with pointer

void	identify(Base *p)
{
	Base	*obj;

	obj = dynamic_cast<A *>(p);
	if (obj)
		std::cout << "A" << std::endl;

	obj = dynamic_cast<B *>(p);
	if (obj)
		std::cout << "B" << std::endl;

	obj = dynamic_cast<C *>(p);
	if (obj)
		std::cout << "C" << std::endl;
}

void	identify(Base *p, std::string &type)
{
	Base	*obj;

	obj = dynamic_cast<A *>(p);
	if (obj)
	{
		type = "A";
		return ;
	}

	obj = dynamic_cast<B *>(p);
	if (obj)
	{
		type = "B";
		return ;
	}

	obj = dynamic_cast<C *>(p);
	if (obj)
	{
		type = "C";
		return ;
	}
	type = "Unknown";
}


// identify with reference

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

void	identify(Base &p, std::string &type)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		type = "A";
		return ;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		type = "B";
		return ;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		type = "C";
		return ;
	}
	catch (std::exception &e)
	{
	}
	type = "Unknown";
}