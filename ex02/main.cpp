/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:05:17 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 16:19:59 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"
#include "ABC.h"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		Base *base = generate();
		std::cout << "Identify by pointer: ";
		identify(base);
		std::cout << "Identify by reference: ";
		identify(*base);
		delete base;
		return (0);
	}
	else
	{
		int	res;
		for (int i = 1; i < ac; i++)
		{
			std::string	className = av[i];
			std::string	classNameRes;
			Base		*base;
			if (className == "A")
				base = new A;
			else if (className == "B")
				base = new B;
			else if (className == "C")
				base = new C;
			else
			{
				className = "Unknown";
				base = new Base;
			}

			identify(base, classNameRes);
			std::cout << "Type of class " << av[i] << " is " << classNameRes << std::endl;
			if (classNameRes != className)
			{
				res++;
				std::cout << "Error: " << classNameRes << " != " << className << std::endl;
			}
			else
				std::cout << "Success" << std::endl;
			identify(*base, classNameRes);
			std::cout << "Type of class " << av[i] << " is " << classNameRes << std::endl;
			if (classNameRes != className)
			{
				res++;
				std::cout << "Error: " << classNameRes << " != " << className << std::endl;
			}
			else
				std::cout << "Success" << std::endl;
			delete base;
		}
		return res;
	}
}