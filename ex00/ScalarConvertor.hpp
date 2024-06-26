/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:21:41 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 12:42:48 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTOR_HPP
# define SCALAR_CONVERTOR_HPP
# include <string>

class ScalarConvertor {
	public:
		static void convert(std::string &str);
		static void convert(std::string &str, std::ostream &os);

	private:
		ScalarConvertor();
		ScalarConvertor(ScalarConvertor const & src);
		~ScalarConvertor();
		ScalarConvertor & operator=(ScalarConvertor const & src);
};

#endif