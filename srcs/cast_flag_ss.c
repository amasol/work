/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_ss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 22:01:16 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 22:01:21 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int g_lob;

static int			cast_flg_ss_h4(t_inf *inf, t_flg *flg, wchar_t *str)
{
	int i;

	i = 0;
	if (flg->wid == 1 && flg->preci == 1 && inf->wid_t > 0)
	{
		inf->un_j = 0;
		inf->cou_t = (inf->wid_t > inf->wid) ? inf->wid_t - inf->wid : 0;
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		while (str[i] && inf->wid != 0 && inf->un_j < inf->wid)
		{
			inf->un_j += ft_lenwchar(str[i]);
			if (inf->wid >= inf->un_j && inf->un_j <= inf->wid)
			{
				ft_putwchar(str[i], inf);
				inf->wid -= inf->un_j;
				inf->un_j = 0;
			}
			i++;
		}
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_ss_h5(inf, flg, str);
	return (0);
}

static int			cast_flg_ss_h3(t_inf *inf, t_flg *flg, wchar_t *str)
{
	int i;

	i = 0;
	if (flg->wid == 1 && flg->preci == 1 && flg->check_preci == 0)
	{
		inf->un_j = 0;
		while (str[i] && inf->wid != 0 && inf->un_j < inf->wid)
		{
			inf->un_j += ft_lenwchar(str[i]);
			if (inf->wid >= inf->un_j && inf->un_j <= inf->wid)
			{
				ft_putwchar(str[i], inf);
				inf->wid -= inf->un_j;
				inf->un_j = 0;
			}
			i++;
		}
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_ss_h4(inf, flg, str);
	return (0);
}

static int			cast_flg_ss_h2(t_inf *inf, t_flg *flg, wchar_t *str)
{
	int i;

	i = 0;
	if (flg->wid == 1 && flg->preci == 1
			&& flg->check_preci == 1 && flg->zero == 1)
	{
		inf->cou = inf->wid;
		inf->r = (inf->cou > 0 && str[i] != '\0')
				? inf->r += ps_l("0", inf->cou) : inf->r;
	}
	else if (flg->wid == 1 && flg->preci == 1
			&& flg->check_preci == 1 && inf->wid_t == 0)
	{
		inf->cou = inf->wid;
		inf->r = (inf->cou > 0 && str[i] != '\0')
				? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_ss_h3(inf, flg, str);
	return (0);
}

static int			cast_flg_ss_h(t_inf *inf, t_flg *flg, wchar_t *str)
{
	int i;

	i = 0;
	if (flg->wid == 1 && flg->preci == 0 && flg->zero == 0)
	{
		inf->cou = (inf->un_j < inf->wid) ? inf->wid - inf->un_j : inf->cou;
		inf->r = (inf->cou > 0 && flg->min == 0)
				? inf->r += ps_l(" ", inf->cou) : inf->r;
		while (str[i])
			ft_putwchar(str[i++], inf);
		inf->r = (inf->cou > 0 && flg->min == 1)
				? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	else if (flg->zero == 1 && flg->preci == 0 && flg->wid == 1)
	{
		inf->cou = (inf->un_j < inf->wid) ? inf->wid - inf->un_j : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		while (str[i])
			ft_putwchar(str[i++], inf);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_ss_h2(inf, flg, str);
	return (0);
}

int					cast_flg_ss(t_inf *inf, t_flg *flg, wchar_t *str)
{
	int i;

	i = 0;
	g_lob = inf->r;
	while (str && str[i])
		inf->un_j += ft_lenwchar(str[i++]);
	i = 0;
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
	cast_flg_ss_h(inf, flg, str);
	return (0);
}
