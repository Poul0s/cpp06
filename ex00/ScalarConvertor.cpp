/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:27:52 by psalame           #+#    #+#             */
/*   Updated: 2024/05/07 08:37:53 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cerrno>

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

	if (str[str.size() - 1] == 'f')
	{
		if (str.find(".") == std::string::npos)
			return (false);
		str = str.substr(0, str.size() - 1);
	}

	char	*endptr;
	float	nb = strtof(str.c_str(), &endptr);
	if (*endptr != '\0')
	{
		return (false);
	}
	if (nb == std::numeric_limits<float>::infinity() || nb == -std::numeric_limits<float>::infinity() || std::isnan(nb))
		return (false);
	return (true);
}

static bool	isInt(std::string &str)
{
	char	*endptr;
	errno = 0;
	long int	nb = strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0' || errno == ERANGE || nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		return (false);
	return (true);
}

static bool	isDouble(std::string &str)
{
	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
		return (true);

	char	*endptr;
	double	nb = strtod(str.c_str(), &endptr);
	if (*endptr != '\0')
		return (false);
	if (nb == std::numeric_limits<double>::infinity() || nb == -std::numeric_limits<double>::infinity() || std::isnan(nb))
		return (false);
	return (true);
}

static short	getStringType(std::string &str)
{
	if (str.size() == 0)
		return (-1);
	else if (str.size() == 1 && !isdigit(str[0]))
		return (0);
	else if (str[str.size() - 1] == 'f' && isFloat(str))
		return (2);
	else if (isInt(str))
		return (1);
	else if (isDouble(str))
		return (3);
	return (-1);
}

static void	convertFromChar(std::string &str, std::ostream &os)
{
	char	c = str[0];

	os << "char: '" << c << "'" << std::endl;
	os << "int: " << static_cast<int>(c) << std::endl;
	os << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	os << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void	convertFromInt(std::string &str, std::ostream &os)
{
	int	nb = static_cast<int>(strtol(str.c_str(), NULL, 10));

	if (nb < std::numeric_limits<char>::min() || nb > std::numeric_limits<char>::max())
		os << "char: impossible" << std::endl;
	else if (nb < 32 || nb > 126)
		os << "char: Non displayable" << std::endl;
	else
		os << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	os << "int: " << nb << std::endl;
	os << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;
	os << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
}

static void	convertFromFloat(std::string &str, std::ostream &os)
{
	float				nb;
	if (str == "inff" || str == "+inff")
		nb = std::numeric_limits<float>::infinity();
	else if (str == "-inff")
		nb = -std::numeric_limits<float>::infinity();
	else if (str == "nanf")
		nb = std::numeric_limits<float>::quiet_NaN();
	else
	{
		nb = std::strtof(str.c_str(), NULL);
	}


	if (std::isnan(nb) || nb < std::numeric_limits<char>::min() || nb > std::numeric_limits<char>::max())
		os << "char: impossible" << std::endl;
	else if (nb < 32 || nb > 126)
		os << "char: Non displayable" << std::endl;
	else
		os << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	
	if (std::isnan(nb) || nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		os << "int: impossible" << std::endl;
	else
		os << "int: " << static_cast<int>(nb) << std::endl;
	
	os << "float: " << std::fixed << std::setprecision(1) << nb << "f" << std::endl;
	
	os << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nb) << std::endl;
}

static void	convertFromDouble(std::string &str, std::ostream &os)
{
	double				nb;
	if (str == "inf" || str == "+inf")
		nb = std::numeric_limits<double>::infinity();
	else if (str == "-inf")
		nb = -std::numeric_limits<double>::infinity();
	else if (str == "nan")
		nb = std::numeric_limits<double>::quiet_NaN();
	else
	{
		nb = std::strtod(str.c_str(), NULL);
	}

	if (std::isnan(nb) || nb < std::numeric_limits<char>::min() || nb > std::numeric_limits<char>::max())
		os << "char: impossible" << std::endl;
	else if (nb < 32 || nb > 126)
		os << "char: Non displayable" << std::endl;
	else
		os << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	
	if (std::isnan(nb) || nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		os << "int: impossible" << std::endl;
	else
		os << "int: " << static_cast<int>(nb) << std::endl;
	
	os << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nb) << "f" << std::endl;

	os << "double: " << std::fixed << std::setprecision(1) << nb << std::endl;
}

void	ScalarConvertor::convert(std::string &str)
{
	ScalarConvertor::convert(str, std::cout);
}

void	ScalarConvertor::convert(std::string &str, std::ostream &os)
{
	short	type;

	type = getStringType(str);
	switch (type)
	{
		case 0:
			convertFromChar(str, os);
			break;
		case 1:
			convertFromInt(str, os);
			break;
		case 2:
			convertFromFloat(str, os);
			break;
		case 3:
			convertFromDouble(str, os);
			break;
		default:
			os << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: impossible" << std::endl
			<< "double: impossible" << std::endl;
			break;
	}
}

