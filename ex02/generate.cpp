/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:59:38 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 16:17:43 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABC.hpp"
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	std::srand(std::time(0));
	int i = std::rand() % 3;
	if (i == 0)
		return new A;
	else if (i == 1)
		return new B;
	else
		return new C;
}
