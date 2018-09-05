/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:07:32 by amasol            #+#    #+#             */
/*   Updated: 2018/09/03 16:07:34 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		cast_flg_c_help(t_inf *inf, t_flg *flg, char str)
{
	if (flg->wid == 1 && flg->preci == 0 && flg->min == 1)
	{
		ft_putchar(str);
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	else if (flg->preci == 1 && inf->cou > 0 &&
			inf->cou_t == 0 && flg->min != 1)
	{
		if ((flg->pls == 1) && flg->min == 0 && (inf->wid < inf->wid_t))
			inf->r += write(1, " ", 1);
		ft_putchar(str);
	}
	else if (inf->nothi == 0)
		ft_putchar(str);
	else if (flg->space == 1)
		ft_putchar(str);
	inf->r += 1;
}

void			cast_flg_c(t_inf *inf, t_flg *flg, char str)
{
	inf->cou = (inf->un_j > inf->wid) ? inf->un_j : inf->wid - inf->un_j;
	if (inf->wid_t > inf->wid)
		inf->cou_t = (inf->wid_t > inf->wid) ? inf->wid_t - inf->wid : 0;
	else if (flg->min == 1 && flg->preci == 0 && inf->wid == 0)
	{
		inf->r = (flg->space == 1) ? inf->r += write(1, " ", 1) : inf->r;
		ft_putchar(str);
	}
	else if (flg->zero == 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou -= 1) : inf->r;
		if (str == '\0')
		{
			ft_putchar('0');
			ft_putchar('\0');
			inf->r += 1;
		}
	}
	else if (inf->cou >= 0 && flg->wid == 1 && flg->preci == 0
		&& flg->min != 1 && inf->min_v != 1)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		ft_putchar(str);
	}
	cast_flg_c_help(inf, flg, str);
}

void			cast_flg_cc(t_inf *inf, t_flg *flg, wchar_t c)
{
	inf->un_j = ft_lenwchar(c, inf);
	if (flg->wid == 1 && flg->preci == 0)
	{
		inf->cou = (inf->un_j < inf->wid) ? inf->wid - inf->un_j : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		ft_putwchar(c, inf);
	}
	else if (flg->wid == 1 && flg->preci == 1 && flg->check_preci == 1)
	{
		inf->cou = (inf->un_j < inf->wid) ? inf->wid - inf->un_j : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		ft_putwchar(c, inf);
	}
	else if (flg->space == 1 || flg->pls == 1)
	{
		inf->cou = (inf->un_j < inf->wid) ? inf->wid - inf->un_j : inf->cou;
		inf->r = (inf->cou > 0) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		ft_putwchar(c, inf);
	}
	else if (flg->preci == 1)
		ft_putwchar(c, inf);
	else if (flg->wid == 0 && flg->preci == 0 && flg->pls == 0)
		ft_putwchar(c, inf);
}
