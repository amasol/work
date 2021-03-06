/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 20:36:43 by amasol            #+#    #+#             */
/*   Updated: 2018/08/28 20:36:44 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_lenwchar(wchar_t c, t_inf *inf)
{
	if (c <= 0x7F)
	{
		inf->w_ch += 1;
		return (1);
	}
	else if (c <= 0x7FF)
	{
		inf->w_ch += 2;
		return (2);
	}
	else if (c <= 0xFFFF)
	{
		inf->w_ch += 3;
		return (3);
	}
	else if (c <= 0x10FFFF)
	{
		inf->w_ch += 4;
		return (4);
	}
	return (0);
}
