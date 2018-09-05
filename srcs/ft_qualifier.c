/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qualifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 17:17:30 by amasol            #+#    #+#             */
/*   Updated: 2018/05/08 17:17:31 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int g_help;

int		ft_qualifier(char s)
{
	if (s == 's' || s == 'S' || s == 'Z'
		|| s == 'p' || s == 'd'
		|| s == 'P' || s == 'i'
		|| s == 'o' || s == 'O'
		|| s == 'u' || s == 'U'
		|| s == 'x' || s == 'X'
		|| s == 'c' || s == 'C'
		|| s == '%' || s == 'D')
	{
		g_help = 1;
		return (1);
	}
	else
	{
		g_help = 0;
		return (0);
	}
}

int		ft_refinement(char s)
{
	if (s == 'D' || s == 'd' || s == 'i')
		return (1);
	else if (s == 'c' || s == 'C')
		return (2);
	else if (s == 's' || s == 'S')
		return (3);
	else if (s == 'x' || s == 'X')
		return (4);
	else if (s == 'o' || s == 'O')
		return (5);
	else if (s == 'u' || s == 'U')
		return (6);
	else if (s == 'p')
		return (7);
	return (0);
}

int		output_after(char *format, va_list lst, t_flg *flg, t_inf *inf)
{
	int i;

	i = 0;
	if (format[i] == 'Z')
	{
		pars_hi_z(flg, inf, lst);
		return (1);
	}
	while (ft_isdigit(format[i]) || ft_flg_check(format[i]))
		i++;
	if (ft_qualifier(format[i]))
		i++;
	if (g_help == 0 && flg->min == 0)
	{
		inf->wid -= 1;
		inf->r = (flg->wid == 1) ? inf->r += ps_l(" ", inf->wid) : inf->r;
	}
	while (format[i] != '%' && format[i] != '\0')
	{
		inf->r += write(1, &format[i], 1);
		i++;
	}
	inf->cou_format = i;
	return (1);
}

int		is_check_preci(char *str, t_flg *flg)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]))
	{
		i++;
		if (str[i] == '.')
			flg->check_preci = 1;
		return (1);
	}
	return (0);
}

int		is_check_specs(char s)
{
	if (s == 'A' || s == 'B' || s == 'E' || s == 'F'
		|| s == 'G' || s == 'H' || s == 'I' || s == '{' || s == '}'
		|| s == 'J' || s == 'K' || s == 'L' || s == 'M'
		|| s == 'N' || s == 'O' || s == 'P' || s == 'Q'
		|| s == 'R' || s == 'S' || s == 'T' || s == 'V'
		|| s == 'W' || s == 'Y' || s == 'Z' || s == '\n')
		return (1);
	else
		return (0);
}
