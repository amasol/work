/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:12:03 by amasol            #+#    #+#             */
/*   Updated: 2018/09/03 16:12:13 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	g_lob;

static int	cast_flg_di_h4(t_inf *inf, intmax_t i, t_flg *flg, char *str)
{
	if (flg->preci == 1 && flg->min == 1)
	{
		if ((flg->pls == 1 || inf->tmp == 1) && inf->min_v != 1)
			inf->r += write(1, "+", 1);
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
	}
	else if (flg->slash == 1)
	{
		if (*str == 'X')
			inf->r += write(1, "0X", 2);
		if (*str == 'x')
			inf->r += write(1, "0x", 2);
		if (*str == 'o' || *str == 'O')
			inf->r += write(1, "0", 1);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_di_h5(inf, i, flg);
	return (0);
}

static int	cast_flg_di_h3(t_inf *inf, intmax_t i, t_flg *flg, char *str)
{
	if (flg->preci == 1 && inf->cou_t >= 0 && flg->min == 0 && i != 0)
	{
		inf->cou_t = (inf->min_v == 1) ? inf->cou_t -= 1 : inf->cou_t;
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		inf->r = (flg->pls == 1) ? inf->r += write(1, "+", 1) : inf->r;
		inf->r = (inf->min_v == 1) ? inf->r += write(1, "-", 1) : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	else if (flg->preci == 1 && i == 0)
	{
		if (inf->cou != 0 && inf->cou_t > 0)
			inf->r += ps_l(" ", inf->cou_t);
		if (inf->wid_t > 0 && i == 0 && inf->cou == 0)
			inf->r += ps_l(" ", inf->wid_t);
		if (inf->wid > 0 && i == 0)
			inf->r += ps_l("0", inf->wid);
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_di_h4(inf, i, flg, str);
	return (0);
}

static int	cast_flg_di_h2(t_inf *inf, intmax_t i, t_flg *flg, char *str)
{
	if (flg->wid == 1 && flg->preci == 0 &&
			 flg->min != 1 && inf->min_v != 1 && flg->space == 1)
	{
		inf->cou += 1;
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	else if (flg->preci == 1 && inf->cou > 0 &&
		inf->cou_t == 0 && flg->space != 1)
	{
		inf->cou = (inf->min_v == 1
			&& inf->wid_t == 0) ? inf->cou += 1 : inf->cou;
		if ((inf->min_v == 0 && flg->min == 0) && flg->pls == 0)
			;
		inf->r = (inf->min_v == 1) ? inf->r += write(1, "-", 1) : inf->r;
		if (inf->cou > 0 && i != 0)
			inf->r += ps_l("0", inf->cou);
		if (i == 0 && inf->wid != inf->wid_t)
			inf->r += ps_l(" ", inf->wid);
		inf->r += (i != 0) ? ft_cou_int(ft_putnbr_intmax(i)) : 0;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_di_h3(inf, i, flg, str);
	return (0);
}

static int	cast_flg_di_h6(t_inf *inf, intmax_t i, t_flg *flg, char *str)
{
	if (flg->preci == 1 && inf->cou > 0
			&& inf->cou_t == 0 && flg->space == 1)
	{
		inf->r = (flg->space == 1 && inf->wid_t != 0)
			? inf->r += write(1, " ", 1) : inf->r;
		inf->r = (inf->min_v == 1) ? inf->r += write(1, "-", 1) : inf->r;
		if (inf->cou > 0 && i != 0)
			inf->r += ps_l("0", inf->cou);
		if (i == 0 && inf->wid != inf->wid_t)
			inf->r += ps_l(" ", inf->wid);
		inf->r += (i != 0) ? ft_cou_int(ft_putnbr_intmax(i)) : 0;
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_di_h2(inf, i, flg, str);
	return (0);
}

static int	cast_flg_di_h(t_inf *inf, intmax_t i, t_flg *flg, char *str)
{
	if (flg->wid == 1 && flg->preci == 0 && flg->h == 0 && flg->space != 1)
	{
		if ((flg->min == 1 && inf->min_v == 1) && flg->pls == 0)
			inf->r += write(1, "-", 1);
		if (flg->min == 1)
			inf->min_v = 0;
		if (inf->cou > 0 && flg->space != 1 && inf->min_v == 1)
			inf->r += ps_l(" ", inf->cou);
		inf->r = (inf->min_v == 1) ? inf->r += write(1, "-", 1) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
		if (inf->cou > 0 && flg->space != 1 && inf->min_v == 0)
			inf->r += ps_l(" ", inf->cou);
	}
	else if ((flg->min == 0) && flg->pls == 1 && flg->preci == 0)
	{
		inf->r += write(1, "+", 1);
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_di_h6(inf, i, flg, str);
	return (0);
}

int			cast_flg_di(t_inf *inf, intmax_t i, t_flg *flg, char *str)
{
	g_lob = inf->r;
	if (inf->cou > 0 && flg->preci == 0 && inf->wid == 0)
	{
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
		if (inf->cou > 0 && (!(inf->wid == 1 && i == 1)))
			inf->r += ps_l(" ", inf->cou);
	}
	else if (flg->zero == 1)
	{
		inf->r = (flg->space == 1) ? inf->r += write(1, " ", 1) : inf->r;
		inf->r = (inf->min_v == 1) ? inf->r += write(1, "-", 1) : inf->r;
		inf->r = (flg->pls == 1) ? inf->r += write(1, "+", 1) : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	else if (flg->wid == 1 && flg->preci == 0 &&
				flg->min != 1 && inf->min_v != 1 && flg->space != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	if (g_lob < inf->r)
		return (1);
	cast_flg_di_h(inf, i, flg, str);
	return (0);
}
