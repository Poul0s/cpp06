/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABC.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:05:33 by psalame           #+#    #+#             */
/*   Updated: 2024/05/06 16:15:50 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABC_H
# define ABC_H
# include <iostream>

Base	*generate(void);

void	identify(Base *p);
void	identify(Base *p, std::string &type);
void	identify(Base &p);
void	identify(Base &p, std::string &type);

#endif