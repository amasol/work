/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:48:39 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 15:48:41 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int g_lob;

static int	cast_flg_x_h4(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->preci == 1 && inf->cou > 0 && inf->cou_t == 0)
	{
		if (inf->x == 'x' && flg->slash == 1 && i != 0)
			inf->r += write(1, "0x", 2);
		else if (flg->slash == 1 && i != 0)
			inf->r += write(1, "0X", 2);
		while (inf->cou > 0 && i != 0)
		{
			inf->r += write(1, "0", 1);
			inf->cou--;
		}
		if (i != 0)
		{
			inf->r += ft_strlen_uintmax(str);
			ft_putstr(str);
		}
		inf->r = (inf->wid > 0 && i == 0)
			? inf->r += ps_l(" ", inf->wid) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_x_h5(inf, i, flg, str);
	return (0);
}

static int	cast_flg_x_h3(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->wid == 1 && flg->preci == 0 &&
		(flg->min == 1 || inf->min_v == 1))
	{
		if (inf->x == 'x' && flg->slash == 1)
		{
			inf->r += write(1, "0x", 2);
			inf->cou -= 2;
		}
		else if (flg->slash == 1)
		{
			inf->r += write(1, "0X", 2);
			inf->cou -= 2;
		}
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_x_h4(inf, i, flg, str);
	return (0);
}

static int	cast_flg_x_h2(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
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
	if (g_lob < inf->r)
		return (1);
	cast_flg_x_h3(inf, i, flg, str);
	return (0);
}

static int	cast_flg_x_h(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->zero == 1)
	{
		if (flg->slash == 1 && i != 0)
		{
			inf->r += write(1, "0x", 2);
			inf->cou -= 2;
		}
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		if (i != 0)
		{
			inf->r += ft_strlen_uintmax(str);
			ft_putstr(str);
		}
		return (1);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_x_h2(inf, i, flg, str);
	return (0);
}

int			cast_flg_x(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	g_lob = inf->r;
	if (flg->min == 1)
		flg->zero = 0;
	if (flg->min == 1 && flg->preci == 0 && inf->wid == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_x_h(inf, i, flg, str);
	return (0);
}
