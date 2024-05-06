/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:31:32 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 15:31:56 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data {
	public:
		Data();
		Data(const Data &copy);
		~Data();
		Data &operator=(const Data &copy);
		long	data;
};

#endif