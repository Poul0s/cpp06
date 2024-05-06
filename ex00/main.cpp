/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:23:19 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 13:40:00 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConvertor.hpp"

int	scalarTester(void);

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		return (scalarTester());
	}
	else if (ac == 2)
	{
		std::string	str = av[1];
		ScalarConvertor::convert(str);
	}
	if (ac > 2)
	{
		std::cout << "Usage: ./" << av[0] << " [str value]" << std::endl;
		return (1);
	}
}