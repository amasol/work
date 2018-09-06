/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 17:13:47 by amasol            #+#    #+#             */
/*   Updated: 2018/07/16 17:13:47 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int g_lob;

static int		cast_flg_p_h4(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->preci == 1 && flg->min == 1 && inf->cou >= 0)
	{
		inf->r += write(1, "0x", 2);
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
	}
	else if (flg->min == 1 && i == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_p_h5(inf, flg, str);
	return (0);
}

static int		cast_flg_p_h3(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->preci == 1 && inf->cou >= 0 && flg->min == 0)
	{
		inf->cou = (inf->wid > inf->un_j) ? inf->wid - inf->un_j : 0;
		inf->un_j += 2;
		inf->cou_t = (inf->wid_t > inf->un_j + inf->cou) ?
			inf->wid_t - (inf->un_j + inf->cou) : 0;
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		inf->r += write(1, "0x", 2);
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		if (i != 0)
		{
			inf->r += ft_strlen_uintmax(str);
			ft_putstr(str);
		}
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_p_h4(inf, i, flg, str);
	return (0);
}

static int		cast_flg_p_h2(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->pls == 1 && flg->preci == 0 && inf->wid == 0)
	{
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
	}
	else if (flg->space == 1 && flg->preci != 1 && inf->nothi == 1)
	{
//		inf->r += write(1, " ", 1);
		inf->r += write(1, "0x", 2);
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flg->preci == 1 && inf->cou > 0 && inf->cou_t == 0)
	{
		if (inf->cou_t == 0 && inf->wid >= 4 && i == 0)
			inf->cou += 2;
		inf->r += write(1, "0x", 2);
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_p_h3(inf, i, flg, str);
	return (0);
}

static int		cast_flg_p_h(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (flg->zero == 1 && i != 0)
	{
		inf->r += write(1, "0x", 2);
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		ft_putstr(str);
	}
	else if (flg->wid == 1 && flg->preci == 0 && flg->min != 1)
	{
		inf->r = (inf->cou > 0 && flg->zero != 1)
				? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += ft_strlen_uintmax(str);
		inf->r += write(1, "0x", 2);
		ft_putstr(str);
		inf->r = (flg->zero == 1) ? inf->r += ps_l("0", inf->cou) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_p_h2(inf, i, flg, str);
	return (0);
}

int				cast_flg_p(t_inf *inf, uintmax_t i, t_flg *flg, char *str)
{
	if (inf->cou_t <= 2 && flg->min == 0)
		inf->cou_t = 0;
	else if (inf->cou_t > 2)
		;
	if (inf->cou_t == 0 && inf->cou <= 2)
		inf->cou = 0;
	else if (inf->cou_t == 0 && inf->cou >= 4 && i == 0)
		inf->cou -= 2;
	if (flg->min == 1 && flg->wid == 1 && str != NULL && i != 0)
	{
		inf->cou -= 2;
		inf->r += write(1, "0x", 2);
		inf->r += ft_strlen(str);
		ft_putstr(str);
		inf->cou = (inf->un_j > inf->cou && inf->cou > 0)
			? inf->un_j - inf->cou : inf->cou;
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_p_h(inf, i, flg, str);
	return (0);
}
