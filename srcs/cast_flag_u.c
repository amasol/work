/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_flag_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:47:47 by amasol            #+#    #+#             */
/*   Updated: 2018/09/04 15:47:54 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		cast_flg_u(t_inf *inf, uintmax_t i, t_flg *flg)
{
	if (flg->zero == 1 && i != 0)
	{
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
	else if ((flg->wid == 1 && flg->preci == 0 && flg->min != 1) ||
			(flg->wid == 1 && flg->min == 1))
	{
		inf->r = (flg->min != 1) ? inf->r += ps_l(" ", inf->cou) : inf->r;
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
		inf->r = (flg->min == 1) ? inf->r += ps_l(" ", inf->cou) : inf->r;
	}
	else if ((flg->pls == 1) || (flg->space == 1 && flg->preci != 1))
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	else if (flg->preci == 1 && flg->min == 0)
	{
		inf->r = (inf->cou_t > 0) ? inf->r += ps_l(" ", inf->cou_t) : inf->r;
		inf->r = (inf->cou > 0) ? inf->r += ps_l("0", inf->cou) : inf->r;
		if (i != 0)
			inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
	}
	else if (flg->pls == 0 && flg->slash == 0 && flg->space == 0
			&& flg->zero == 0 && flg->wid == 0 && flg->preci == 0)
		inf->r += ft_cou_uint(ft_putnbr_uintmax_t(i));
}
