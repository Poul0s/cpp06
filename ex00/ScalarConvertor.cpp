/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:27:52 by psalame           #+#    #+#             */
/*   Updated: 2024/04/28 01:16:20 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"
#include <iostream>
#include <sstream>
#include <limits>

ScalarConvertor::ScalarConvertor()
{
}

ScalarConvertor::ScalarConvertor(const ScalarConvertor &copy)
{
	*this = copy;
}

ScalarConvertor::~ScalarConvertor()
{
}

ScalarConvertor &ScalarConvertor::operator=(ScalarConvertor const &copy)
{
	(void)copy;
	return *this;
}

static bool	isFloat(std::string &str)
{
	if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf")
		return (true);

	std::istringstream	iss(str);
	float				nb;

	iss >> nb;
	return (iss.eof() && !iss.fail());
}

static bool	isInt(std::string &str)
{
	std::istringstream	iss(str);
	int 				nb;

	iss >> nb;
	return (iss.eof() && !iss.fail()); 
}

static bool	isDouble(std::string &str)
{
	std::istringstream	iss(str);
	double 				nb;

	iss >> nb;
	return (iss.eof() && !iss.fail()); 
}

static short	getStringType(std::string &str)
{
	if (str.size() == 0)
		return (-1);
	else if (str.size() == 1)
		return (0);
	else if (str[str.size() - 1] == 'f' && isFloat(str))
		return (1);
	else if (isInt(str))
		return (2);
	else if (isDouble(str))
		return (3);
	return (-1);
}

static void	convertFromChar(std::string &str)
{
	char	c = str[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void	convertFromInt(std::string &str)
{
	int		nb = std::stoi(str);

	if (nb < std::numeric_limits<char>::min() || nb > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (nb < 32 || nb > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	std::cout << "int: " << nb << std::endl;
	
}

void ScalarConvertor::convert(std::string &str)
{
	short	type;

	type = getStringType(str);
	switch (type)
	{
		case 0:
			std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: impossible" << std::endl
			<< "double: impossible" << std::endl;
			break;
	}
}

