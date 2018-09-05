/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:36:05 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 14:36:07 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int g_lob;

static int	cast_flg_x_h7(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->wid == 1 && flg->preci == 0 && flg->min != 1)
	{
		if (flg->slash == 1)
			inf->cou -= 2;
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		if (inf->x == 'x' && flg->slash == 1 && i != 0)
			inf->r += write(1, "0x", 2);
		else if (flg->slash == 1 && i != 0)
			inf->r += write(1, "0X", 2);
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if ((flg->zero == 0 || flg->min == 0)
			&& flg->pls == 1 && flg->preci == 0 && inf->wid == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flg->pls == 0 && flg->slash == 0
			&& flg->zero == 0 && flg->wid == 0 && flg->preci == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	return (0);
}

static int	cast_flg_x_h6(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->preci == 1 && inf->cou == 0 && inf->cou_t > 0)
	{
		inf->r = (inf->wid_t > 0) ? inf->r += ps_l(" ", inf->wid_t) : inf->r;
		if (i != 0)
		{
			inf->r += ft_strlen_uintmax(str);
			ft_putstr(str);
		}
	}
	else if (flg->slash == 1)
	{
		if (inf->x == 'x' && i != 0)
			inf->r += write(1, "0x", 2);
		else if (inf->x == 'X' && i != 0)
			inf->r += write(1, "0X", 2);
		else if (i != 0)
			inf->r += write(1, "0", 1);
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_x_h7(inf, i, flg, str);
	return (0);
}

int			cast_flg_x_h5(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	g_lob = inf->r;
	if (flg->preci == 1 && flg->min == 0 && i != 0)
	{
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		if (inf->x == 'x' && flg->slash == 1)
			inf->r += write(1, "0x", 2);
		else if (flg->slash == 1)
			inf->r += write(1, "0X", 2);
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flg->preci == 1 && flg->min == 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_x_h6(inf, i, flg, str);
	return (0);
}

int			ft_flg_check(char c)
{
	if (c == '+' || c == '-' || c == 'Z'
		|| c == '#' || c == '.'
		|| c == ' ' || c == 'h'
		|| c == 'j' || c == 'z'
		|| c == 'l' || (c == 'l' && c + 1 == 'l')
		|| (c == 'h' && c + 1 == 'h'))
		return (1);
	else
		return (0);
}

int			is_zero(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			return (1);
		else if (str[i] == '0')
			return (0);
		i++;
	}
	return (1);
}
