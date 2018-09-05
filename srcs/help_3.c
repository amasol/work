/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:19:28 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 18:19:29 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int g_lob;

static void		initialization_flg_h(t_flg *flg, t_inf *inf)
{
	inf->wid = 0;
	inf->wid_t = 0;
	inf->cou = 0;
	inf->cou_t = 0;
	inf->cou_three = 0;
	inf->cou_four = 0;
	inf->tmp = 0;
	inf->cou_format = 0;
	inf->min_v = 0;
	inf->un_j = 0;
	inf->intm_j = 0;
	inf->nothi = 0;
	inf->zz = 0;
	flg->nothi_flg = 0;
}

void			initialization_flg(t_flg *flg, t_inf *inf)
{
	flg->pls = 0;
	flg->min = 0;
	flg->slash = 0;
	flg->space = 0;
	flg->zero = 0;
	flg->wid = 0;
	flg->preci = 0;
	flg->check_preci = 0;
	flg->zero_preci = 0;
	flg->hh = 0;
	flg->h = 0;
	flg->ll = 0;
	flg->l = 0;
	flg->j = 0;
	flg->z = 0;
	initialization_flg_h(flg, inf);
}

void			parsing_four(char *str, t_flg *flg, t_inf *inf)
{
	int i;

	i = 0;
	while (str[i] == '+' || (str[i] == '0' && flg->zero != 1)
			|| str[i] == '-' || str[i] == ' ' || ft_flg_check(str[i]))
		i++;
	if (ft_isdigit(str[i]) && inf->cou_three != 1)
	{
		if (str[i] >= '0' && str[i] <= '9')
			inf->wid_t = ft_atoi(&str[i]);
	}
}

void			parsing_five(char *str, t_inf *inf, t_flg *flg)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (inf->wid_t > 0 && inf->wid == 0 && inf->cou_four == 0
		&& flg->zero_preci != 1)
		inf->wid = inf->wid_t;
	while (ft_flg_check(str[i]))
		i++;
	if (str[i])
	{
		while (ft_isdigit(str[i++]))
			k = 1;
		while (ft_flg_check(str[i]))
			i++;
		while (ft_isdigit(str[i++]))
			k = 2;
		if (k == 1)
			inf->wid_t = 0;
	}
	inf->cou_three = 1;
}

int				cast_flg_di_h6(t_inf *inf, intmax_t i, t_flg *flg, char *str)
{
	if ((flg->min == 0) && flg->pls == 1 && flg->preci == 0)
	{
		inf->r += write(1, "+", 1);
		inf->r += ft_cou_int(ft_putnbr_intmax(i));
	}
	else if (flg->preci == 1 && inf->cou > 0
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
