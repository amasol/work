/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 21:02:48 by amasol            #+#    #+#             */
/*   Updated: 2018/09/03 21:02:49 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int g_lob;

static int		cast_flg_s_h4(t_inf *inf, t_flg *flg, char *str, char *tmp)
{
	if (inf->wid_t <= inf->wid && flg->min == 0 && inf->nothi == 1)
	{
		inf->wid_t = (inf->wid > inf->un_j)
				? inf->wid_t - inf->un_j : inf->wid_t;
		inf->wid_t = (inf->wid < inf->un_j)
				? inf->wid_t - inf->wid : inf->wid_t;
		inf->r = (inf->wid_t > 0) ? inf->r += ps_l(" ", inf->wid_t) : inf->r;
		tmp = ft_strsub(str, 0, inf->wid);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_s_h5(inf, flg, str, tmp);
	return (0);
}

static int		cast_flg_s_h3(t_inf *inf, t_flg *flg, char *str, char *tmp)
{
	if (flg->preci == 1 && inf->wid_t == 0 && flg->nothi_flg == 1)
	{
		inf->cou = (inf->wid > inf->un_j) ? inf->un_j : inf->wid;
		tmp = ft_strsub(str, 0, inf->cou);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
	else if (inf->wid_t >= inf->wid && flg->min == 0 && inf->nothi == 1)
	{
		inf->wid_t = (inf->wid >= inf->un_j)
				? inf->wid_t - inf->un_j : inf->wid_t;
		inf->wid_t = (inf->wid < inf->un_j)
				? inf->wid_t - inf->wid : inf->wid_t;
		inf->r = (inf->wid_t > 0) ? inf->r += ps_l(" ", inf->wid_t) : inf->r;
		tmp = ft_strsub(str, 0, inf->wid);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_s_h4(inf, flg, str, tmp);
	return (0);
}

static int		cast_flg_s_h2(t_inf *inf, t_flg *flg, char *str, char *tmp)
{
	if (flg->wid == 1 && flg->preci == 0 && flg->min == 1)
	{
		tmp = ft_strsub(str, 0, inf->wid);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	else if (flg->preci == 1 && inf->wid_t == 0 && flg->check_preci == 1)
		inf->r = (inf->wid > 0) ? inf->r += ps_l(" ", inf->wid) : inf->r;
	if (g_lob < inf->r)
		return (1);
	cast_flg_s_h3(inf, flg, str, tmp);
	return (0);
}

static int		cast_flg_s_h(t_inf *inf, t_flg *flg, char *str, char *tmp)
{
	if (flg->zero == 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		tmp = ft_strsub(str, 0, inf->wid);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
	}
	else if (flg->wid == 1 && flg->preci == 0 &&
			flg->min != 1 && inf->min_v != 1 && inf->nothi == 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		tmp = ft_strsub(str, 0, inf->wid);
		inf->r += ft_strlen_uintmax(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_s_h2(inf, flg, str, tmp);
	return (0);
}

int				cast_flg_s(t_inf *inf, t_flg *flg, char *str)
{
	char *tmp;

	tmp = NULL;
	g_lob = inf->r;
	inf->cou = (inf->un_j > inf->wid)
			? inf->un_j : inf->wid - inf->un_j;
	if (inf->wid_t > inf->wid)
		inf->cou_t = (inf->wid_t > inf->wid) ? inf->wid_t - inf->wid : 0;
	if (str == NULL && (flg->space == 1 || inf->nothi == 0 || flg->pls == 1))
	{
		inf->wid = (inf->wid == 6 || inf->wid > 6) ? 6 : inf->wid;
		if (flg->wid == 1 && inf->wid)
			inf->r += ps_l("(null)", inf->wid);
		else
			inf->r += write(1, "(null)", 6);
	}
	else if (str == NULL)
		inf->r = (inf->wid > 0) ? inf->r += ps_l("0", inf->wid) : inf->r;
	if (g_lob < inf->r)
		return (1);
	cast_flg_s_h(inf, flg, str, tmp);
	return (0);
}
