/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:23:19 by psalame           #+#    #+#             */
/*   Updated: 2024/05/07 09:26:02 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConvertor.hpp"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string	str = av[1];
		ScalarConvertor::convert(str);
	}
	else
	{
		std::cout << "Usage: " << av[0] << " <value>" << std::endl;
		return (1);
	}
}