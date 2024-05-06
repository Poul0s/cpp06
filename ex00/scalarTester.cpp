/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalarTester.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:34:54 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 13:59:44 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include "ScalarConvertor.hpp"

bool	checkScalarOutput(std::string &str, int test_nb)
{
	std::fstream	output;
	std::ifstream	expected;

	output.open("tests/output.txt", std::ios::out);
	if (!output.is_open())
	{
		std::cerr << "Error: could not open test output file in write mode" << std::endl;
		return (false);
	}

	ScalarConvertor::convert(str, output);
	output.close();
	output.open("tests/output.txt", std::ios::in);
	if (!output.is_open())
	{
		std::cerr << "Error: could not open test output file in read mode" << std::endl;
		return (false);
	}
	std::stringstream	expectedFilename;
	expectedFilename << "tests/res" << test_nb << ".txt";
	expected.open(expectedFilename.str().c_str(), std::ios::in);
	if (!expected.is_open())
	{
		std::cerr << "Error: could not open test expected file" << std::endl;
		output.close();
		return (false);
	}

	std::string	outputStr = std::string(std::istreambuf_iterator<char>(output), std::istreambuf_iterator<char>());
	std::string	expectedStr = std::string(std::istreambuf_iterator<char>(expected), std::istreambuf_iterator<char>());
	output.close();
	expected.close();
	if (outputStr != expectedStr)
		std::cerr << "Error: output does not match expected output" << std::endl;
	return (outputStr == expectedStr);
}

int	scalarTester(void)
{
	int	nb_errors = 0;
	int	line_i = 0;
	std::ifstream file;

	file.open("tests/input.txt", std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "Error: could not open test input file" << std::endl;
		return (1);
	}
	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		if (line.empty())
			continue;
		line_i++;
		std::cout << "Test " << line_i << ": ";
		try
		{
			if (!checkScalarOutput(line, line_i))
				nb_errors++;
			else
				std::cout << "Success." << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			nb_errors++;
		}
	}
	file.close();
	return nb_errors;
}