/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:33:10 by amasol            #+#    #+#             */
/*   Updated: 2018/07/08 21:16:54 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_atoi(const char *str)
{
	char				*s;
	unsigned long int	nom;
	int					negativ;

	s = (char *)str;
	nom = 0;
	negativ = 1;
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		negativ = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
	{
		nom = nom * 10 + *s - 48;
		s++;
		if (nom >= 9223372036854775807 && negativ == 1)
			return (-1);
		else if (nom > 9223372036854775807 && negativ == -1)
			return (0);
	}
	nom *= negativ;
	return (nom);
}
