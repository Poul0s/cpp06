/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:58:27 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 15:59:08 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABC_HPP
# define ABC_HPP

class Base {
	public:
		virtual ~Base();
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

#endif