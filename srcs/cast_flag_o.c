/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:02:06 by amasol            #+#    #+#             */
/*   Updated: 2018/09/03 21:02:07 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	g_lob;

static int		cast_flg_o_h3(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->preci == 1 && inf->cou_t >= 0 && flg->min == 0)
	{
		inf->r = (i != 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		inf->r = (i == 0) ? inf->r += ps_l(" ", inf->wid_t) : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r = (flg->slash == 1) ? inf->r += write(1, "0", 1) : inf->r;
		inf->r += (i != 0) ? ft_strlen_uintmax(str) : 0;
		ft_putstr(str = (i == 0) ? 0 : str);
	}
	else if (flg->pls == 0 && flg->slash == 0
		&& flg->zero == 0 && flg->wid == 0 && flg->preci == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flg->wid == 1 && flg->preci == 0 && flg->min == 1)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	return (0);
}

static int		cast_flg_o_h2(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if ((flg->zero == 0 || flg->min == 0) && flg->pls == 1
		&& flg->preci == 0 && inf->wid == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flg->preci == 1 && inf->cou > 0
			&& inf->cou_t == 0 && flg->min != 1)
	{
		inf->r += (i != 0) ? ps_l("0", inf->cou) : ps_l(" ", inf->cou);
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str = (i == 0) ? " " : str);
	}
	else if (flg->preci == 1 && flg->min == 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : 0;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_o_h3(inf, i, flg, str);
	return (0);
}

static int		cast_flg_o_h(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->zero == 1 && flg->min != 1 && flg->slash != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += (i != 0) ? ft_strlen_uintmax(str) : 0;
		ft_putstr(str = (i == 0) ? 0 : str);
	}
	else if (flg->zero == 1 && flg->min != 1 && flg->slash != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += (i != 0) ? ft_strlen_uintmax(str) : 0;
		ft_putstr(str = (i == 0) ? 0 : str);
	}
	else if (flg->wid == 1 && flg->preci == 0 && flg->min != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_o_h2(inf, i, flg, str);
	return (0);
}

int				cast_flg_o(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	g_lob = inf->r;
	if (flg->slash == 1 && flg->preci == 0)
	{
		inf->cou -= 1;
		inf->r = (flg->min != 1 && inf->cou > 0) ?
			inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += write(1, "0", 1);
		inf->r += (i != 0) ? ft_strlen_uintmax(str) : 0;
		ft_putstr(str = (i == 0) ? 0 : str);
		inf->r = (flg->min == 1) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	else if (flg->preci == 1 && flg->pls == 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_o_h(inf, i, flg, str);
	return (0);
}
